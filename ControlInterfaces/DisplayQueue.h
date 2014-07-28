#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_

#include "GameList.h"
#include "Displayable.h"

namespace jer
{
    template<class T>
    class DisplayQueue: public GameList<T>
    {
    protected:
        GameList<T> *displayList;
        
    public:
        DisplayQueue(): displayList(this) {};
        virtual ~DisplayQueue() {};
        
    public:
        virtual const SUCCESS display() const override
        {
            return this->foreach(&Displayable::display);
        };
    };
    
    using EasyDisplay = DisplayQueue<Displayable *>;
}

#endif /*_DISPLAY_MANAGER_H_*/