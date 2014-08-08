#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_

#include "GameList.h"
#include "SortList.h"
#include "Displayable.h"

namespace jer
{
    template<class T, class SORT_TYPE = GameList<T> >
    class DisplayQueue: public SORT_TYPE
    {
    protected:
        SORT_TYPE *displayList;
        
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
    using EasyPriorityDisplay = DisplayQueue<Displayable *, SortList<Displayable *> >;
}

#endif /*_DISPLAY_MANAGER_H_*/