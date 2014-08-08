#ifndef _LOOP_ENGINE_H_
#define _LOOP_ENGINE_H_

#include "GameList.h"
#include "SortList.h"
#include "Loopable.h"

namespace jer
{    
    template<class T, class SORT_TYPE = GameList<T> >
    class LoopEngine: public SORT_TYPE
    {
    /// LoopEngine, manages a list of Loopable's
    protected:
        SORT_TYPE *loopList;
        
    public:
        LoopEngine(): loopList(this) {};
        virtual ~LoopEngine() {};
        
    public:
        virtual const SUCCESS loop() override // the generic form of the function attempts to use data locality
        {
            return this->foreach(&Loopable::loop);
        };
    };
    
    using EasyLoop = LoopEngine<Loopable *>;
    using EasyPriorityLoop = LoopEngine<Loopable *, SortList<Loopable *> >;
}

#endif /*_LOOP_ENGINE_H_*/