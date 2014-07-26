#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_

#include "GameList.h"
#include "Displayable.h"

namespace jer
{
    template<class T, bool PRIORITY>
    class DisplayQueue: public GameList<T, PRIORITY>
    {
    protected:
        GameList<T> *displayList;
        
    public:
        DisplayQueue(): displayList(this) {};
        virtual ~DisplayQueue() {};
        
    public:
        virtual const SUCCESS display() const override
        {
            SUCCESS ret = 0;
            T *data = displayList->data();
            int n = displayList->size();
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                ret |= data[i].display();
            }
            
            return ret;
        };
    };
    
    template<class T, bool PRIORITY>
    class DisplayQueue<T *, PRIORITY>: public GameList<T *, PRIORITY>
    {
    protected:
        GameList<T *, PRIORITY> *displayList;
        
    public:
        DisplayQueue(): displayList(this) {};
        virtual ~DisplayQueue() {};
        
    public:
        virtual const SUCCESS display() const override
        {
            SUCCESS ret = 0;
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                if(displayList->at(i) == NULL)
                    ret = -1;
                else
                    ret |= displayList->at(i)->display();
            }
            
            return ret;
        };
    };
    
    using EasyDisplay = DisplayQueue<Displayable *, false>;
    using EasyPriorityDisplay = DisplayQueue<Displayable *, true>;
}

#endif /*_DISPLAY_MANAGER_H_*/