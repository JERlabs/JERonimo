#ifndef _LIST_ELEMENTS_H_
#define _LIST_ELEMENTS_H_

#include "Declarations.h"

namespace jer
{
    using std::vector;
    
    template<class T>
    class PriorityElement: public T
    {
    private:
        int priority;
        
    public:
        //PriorityElement(const T& init, const int initP=0): T(init), priority(initP) {};
        PriorityElement(const int initP=0): priority(initP) {};
        PriorityElement(const PriorityElement &other): priority(other.priority) {};
        virtual ~PriorityElement() {};
        
    public:
        const int getPriority() const {return priority;};
        virtual void setPriority(const int p) {priority = p;};
    };
    
    template<class T>
    const bool comparePriorityElements(const PriorityElement<T> &a, const PriorityElement<T> &b)
    {
        return a.getPriority() < b.getPriority();
    }
    
    template<class T>
    const bool comparePriorityElementPointers(PriorityElement<T> *const a, PriorityElement<T> * const b)
    {
        if(a == NULL)
            return true;
        else if(b == NULL)
            return false;
        else
            return a->getPriority() < b->getPriority();
    }
    
    template<class T>
    class ListElement: public T
    {
    public:
        typedef vector<ListElement<T> *> CONTAINING_LIST_TYPE;
        
    private:
        CONTAINING_LIST_TYPE *list;
        unsigned short references;
        
    public:
        ListElement(CONTAINING_LIST_TYPE * const l, const T& init): T(init), references(0) {addSelfToList(l);};
        ListElement(CONTAINING_LIST_TYPE * const l): references(0) {addSelfToList(l);};
        ListElement(const T& init): T(init), list(NULL), references(1) {};
        ListElement(const ListElement& other): T(other), references(other.references) {addSelfToList(other.list);};
        ListElement(): list(NULL), references(1) {};
        virtual ~ListElement() {removeSelfFromList();};
        
    public:
        virtual const bool toDie() {return references == 1;};
        CONTAINING_LIST_TYPE * const getList() const {return list;};
        void addSelfToList(CONTAINING_LIST_TYPE * const l)
        {
            assignList(l);
            if(list)
                list->push_back(this);
        };
        virtual void assignList(CONTAINING_LIST_TYPE * const l)
        {
            list = l;
            if(list)
                references++;
        };
        void removeSelfFromList()
        {
            if(list)
            {
                if(references > 0)
                {
                    references--;
                    list->erase(std::remove(list->begin(), list->end(), this), list->end());
                }
                list = NULL;
            }
        };
        void forgetList()
        {
            if(list) list = NULL;
            references--;
        };
        
        friend class GameList<T *>;
    };
    
    
}


#endif /*_LIST_ELEMENTS_H_*/