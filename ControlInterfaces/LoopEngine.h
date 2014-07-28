#ifndef _LOOP_ENGINE_H_
#define _LOOP_ENGINE_H_

#include "GameList.h"
#include "Loopable.h"

namespace jer
{    
    template<class T>
    class LoopEngine: public GameList<T>
    {
    /// LoopEngine, manages a list of Loopable's
    protected:
        GameList<T> *loopList;
        
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
}

#endif /*_LOOP_ENGINE_H_*/