#ifndef _GAME_LIST_H_
#define _GAME_LIST_H_

#include <vector>
#include <memory>

#include "Declarations.h"

namespace jer
{
    using std::vector;
    using std::shared_ptr;
    
    template<class T>
    class GameList: public T, public vector<T>
    {
    public:
        typedef const SUCCESS (T:: * FOR_CALLBACK)();
        typedef const SUCCESS (T:: * FOR_CONST_CALLBACK)() const;
    protected:
        vector<T> *ourList;
    public:
        GameList(): ourList(this) {};
        virtual ~GameList() {};
        
    public:
        virtual unsigned int getFirst() const {return 0;};
        virtual unsigned int getLast() const {return ourList->size();};
        const SUCCESS foreach(FOR_CALLBACK callBack)
        {
            SUCCESS ret = 0;
            T *data = ourList->data();
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                ret |= (data[i].*callBack)();
            }
            
            return ret;
        };
        
        const SUCCESS foreach(FOR_CONST_CALLBACK callBack) const
        {
            SUCCESS ret = 0;
            T *data = ourList->data();
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                ret |= (data[i].*callBack)();
            }
            
            return ret;
        };
    };
    
    template<class T>
    class GameList<T *>: public T, public vector<shared_ptr<T> >
    {
    public:
        typedef const SUCCESS (T:: * FOR_CALLBACK)();
        typedef const SUCCESS (T:: * FOR_CONST_CALLBACK)() const;
    protected:
        vector<shared_ptr<T> > *ourList;
        
    public:
        GameList(): ourList(this) {};
        virtual ~GameList() {};
        
    public:
        virtual unsigned int getFirst() const {return 0;};
        virtual unsigned int getLast() const {return ourList->size();};
        const SUCCESS foreach(FOR_CALLBACK callBack)
        {
            SUCCESS ret = 0;
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                if(ourList->at(i) == nullptr)
                    ret = -1;
                else
                    ret |= ((*ourList->at(i)).*callBack)();
            }
            
            return ret;
        };
        
        const SUCCESS foreach(FOR_CONST_CALLBACK callBack) const
        {
            SUCCESS ret = 0;
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                if(ourList->at(i) == nullptr)
                    ret = -1;
                else
                    ret |= ((*ourList->at(i)).*callBack)();
            }
            
            return ret;
        };
        
        shared_ptr<T> * const add(T * const elem) // takes the pointer
        {
            ourList->push_back(shared_ptr<T>(elem));
            return &(ourList->back());
        };
        
        template<class U>
        shared_ptr<T> * const copyIn(const U& elem) // copies the object
        {
            ourList->push_back(std::make_shared<U>(elem));
            return &(ourList->back());
        };
    };
   
}


#endif