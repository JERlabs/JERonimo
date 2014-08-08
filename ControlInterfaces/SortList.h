#ifndef _SORT_LIST_H_
#define _SORT_LIST_H_

#include <algorithm>

#include "PriorityElements.h"
#include "GameList.h"

namespace jer
{
    template<class T>
    class SortList: public GameList<PriorityControlInterface<T> >
    {        
    private:
        unsigned int partition;
        
    public:
        SortList(): partition(0) {};
        virtual ~SortList() {};
        
    protected:
        virtual unsigned int getFirst() const {return partition;};
        virtual unsigned int getLast() const {return this->size();};
        
    public:
        virtual void sort()
        {
            std::sort(this->begin(), this->end(), comparePriorityElements);
            for(int i = 0; i < this->size(); i++)
            {
                partition = i;
                if(this->at(i).getPriority() >= 0)
                    break;
            }
            
            if(partition == this->size() - 1 && this->at(partition).getPriority() < 0)
                partition++;
        };
    };
    
    template<class T>
    class SortList<T *>: public GameList<PriorityControlInterface<T> *>
    {
    private:
        unsigned int partition;
        
    public:
        SortList(): partition(0) {};
        virtual ~SortList() {};
        
    public:
        virtual unsigned int getFirst() const {return partition;};
        virtual unsigned int getLast() const {return this->size();};       
        virtual void sort()
        {
            std::sort(this->begin(), this->end(), comparePriorityElementPointers);
            for(int i = 0; i < this->size(); i++)
            {
                partition = i;
                if(this->at(i)->getPriority() >= 0)
                    break;
            }
            
            if(partition == this->size() - 1 && this->at(partition)->getPriority() < 0)
                partition++;
        };
    };
}

#endif /*_SORT_LIST_H_*/