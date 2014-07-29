#ifndef _LOOP_ENGINE_H_
#define _LOOP_ENGINE_H_

#include "GameList.h"
#include "SortList.h"
#include "Loopable.h"

namespace jer
{    
    template<class T, template<class U> class SORT_TYPE = GameList>
    class LoopEngine: public SORT_TYPE<T>
    {
    /// LoopEngine, manages a list of Loopable's
    protected:
        SORT_TYPE<T> *loopList;
        
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
    using EasyPriorityLoop = LoopEngine<Loopable *, SortList>;
}

#endif /*_LOOP_ENGINE_H_*/