#ifndef _GAME_LIST_H_
#define _GAME_LIST_H_

#include <vector>
#include <algorithm>

#include "ListElements.h"


namespace jer
{
    using std::vector;
    
    template<class T, bool PRIORITY>
    class GameList: public ListElement<T>, public vector<T>
    {
    protected:
        vector<T> *ourList;
    public:
        GameList(): ourList(this) {};
        virtual ~GameList() {};
        
    public:
        virtual unsigned int getFirst() const {return 0;};
        virtual unsigned int getLast() const {return ourList->size();};
        virtual void assignList(vector<ListElement<T> *> * const l)
        {
            if(l == this)
                return;
            
            ListElement<T>::assignList(l);
        };
    };
    
    template<class T>
    class GameList<T *, false>: public ListElement<T>, public vector<ListElement<T> *>
    {
    protected:
        vector<ListElement<T> *> *ourList;
        
    public:
        GameList(): ourList(this) {};
        virtual ~GameList()
        {
            for(auto i = ourList->begin(); i != ourList->end(); i++)
            {
                if((*i)->toDie())
                {
                    delete (*i);
                    *i = NULL;
                }
                else
                {
                    (*i)->forgetList();
                }
            }
        };
        
    public:
        virtual unsigned int getFirst() const {return 0;};
        virtual unsigned int getLast() const {return ourList->size();};
        virtual void add(ListElement<T> * const elem)
        {
            if(!elem)
                return;
            
            elem->assignList(this);
            ourList->push_back(elem);
        };
    }; 
    
   template<class T>
   class GameList<T, true>: public GameList<PriorityElement<T>, false>
   {
   private:
       unsigned int partition;
       vector<PriorityElement<T> > *ourList;
       
   public:
       GameList(): partition(0), ourList(this) {};
       virtual ~GameList() {};
       
   public:
       virtual unsigned int getFirst() const {return partition;};
       virtual unsigned int getLast() const {return ourList->size();};
       virtual void sort()
       {
           std::sort(ourList->begin(), ourList->end(), comparePriorityElements);
           for(int i = 0; i < ourList->size(); i++)
           {
               partition = i;
               if(ourList->at(i).getPriority() >= 0)
                   break;
           }
           
           if(partition == ourList->size() - 1 && ourList->at(partition).getPriority() < 0)
               partition++;
       };
   };
   
   template<class T>
   class GameList<T *, true>: public GameList<PriorityElement<T> *, false>
   {
   private:
       unsigned int partition;
       vector<ListElement<PriorityElement<T> > *> *ourList;
       
   public:
       GameList(): partition(0), ourList(this) {};
       virtual ~GameList() {};
       
   public:
       virtual unsigned int getFirst() const {return partition;};
       virtual unsigned int getLast() const {return ourList->size();};
       virtual void add(ListElement<PriorityElement<T> > * const elem)
       {
           if(!elem)
               return;
           
           elem->assignList(this);
           ourList->push_back(elem);
           sort();
       };
       virtual void sort()
       {
           std::sort(ourList->begin(), ourList->end(), comparePriorityElementPointers<T>);
           for(int i = 0; i < ourList->size(); i++)
           {
               partition = i;
               if(ourList->at(i)->getPriority() >= 0)
                   break;
           }
           
           if(partition == ourList->size() - 1 && ourList->at(partition)->getPriority() < 0)
               partition++;
       };
   };
   
   template<class T>
   class ListElement<PriorityElement<T> >: public PriorityElement<T>
   {
   public:
       typedef vector<ListElement<PriorityElement<T> > *> CONTAINING_LIST_TYPE;
       typedef GameList<T *, true> SORT_CONTAINER;
       
   private:
       SORT_CONTAINER *sortList;
       CONTAINING_LIST_TYPE *containingList;
       unsigned short references;
       
   public:
       ListElement(SORT_CONTAINER * const l, const T& init): T(init), references(0) {addSelfToList(l);};
       ListElement(SORT_CONTAINER * const l): references(0) {addSelfToList(l);};
       ListElement(const T& init): sortList(NULL), containingList(NULL), T(init), references(1) {};
       ListElement(): sortList(NULL), containingList(NULL), references(1) {};
       virtual ~ListElement() {removeSelfFromList();};
       
   public:
       virtual const bool toDie() {return references == 1;};
       virtual void setPriority(const int p)
       {
           if(PriorityElement<T>::getPriority() != p)
           {
              PriorityElement<T>::setPriority(p);
              if(sortList)
                  sortList->sort();
           }
       };
       
       void addSelfToList(SORT_CONTAINER * const l)
       {
           assignList(l);
           if(sortList)
           {
               containingList->push_back(this);
               sortList->sort();
           }
       };
       
       void addSelfToList(CONTAINING_LIST_TYPE * const l)
       {
           assignList(l);
           if(containingList)
           {
               containingList->push_back(this);
           }
       };
       
       
       void assignList(SORT_CONTAINER * const l)
       {
           containingList = sortList = l;
           if(containingList)
               references++;
       };
       
       void assignList(CONTAINING_LIST_TYPE * const l)
       {
           containingList = l;
           sortList = NULL;
           if(containingList)
               references++;
       }
       
       void removeSelfFromList()
       {
           if(sortList)
           {
               if(!toDie())
               {
                   references--;
                   sortList->erase(std::remove(sortList->begin(), sortList->end(), this), sortList->end());
                   sortList->sort();
               }
               sortList = NULL;
           }
           else if(containingList)
           {
               if(!toDie())
               {
                   references--;
                   containingList->erase(std::remove(containingList->begin(), containingList->end(), this), containingList->end());
               }
               containingList = NULL;
           }
       }
       
       void forgetList()
       {
           if(sortList) sortList = NULL;
           if(containingList) containingList = NULL;
           references--;
       };
   };
   
//#include "ListElements.impl"
   
}


#endif