#ifndef _LOOP_ENGINE_H_
#define _LOOP_ENGINE_H_

#include "GameList.h"
#include "Loopable.h"

namespace jer
{    
    template<class T, bool PRIORITY>
    class LoopEngine: public GameList<T, PRIORITY>
    {
    /// LoopEngine, manages a list of Loopable's
    protected:
        GameList<T> *loopList;
        
    public:
        LoopEngine(): loopList(this) {};
        virtual ~LoopEngine() {};
        
    public:
        virtual const SUCCESS loop() // the generic form of the function attempts to use data locality
        {
            SUCCESS ret = 0;
            T *data = loopList->data();
            int n = loopList->size();
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                ret |= data[i].loop();
            }
            
            return ret;
        };
    };
    
    template<class T, bool PRIORITY>
    class LoopEngine<T *, PRIORITY>: public GameList<T *, PRIORITY>
    {
    protected:
        GameList<T *, PRIORITY> *loopList;
        
    public:
        LoopEngine(): loopList(this) {};
        virtual ~LoopEngine() {};
        
    public:
        virtual const SUCCESS loop()  // specific form of the function which has more cache misses but easy polymorphism
        {
            SUCCESS ret = 0;
            for(int i = this->getFirst(); i < this->getLast() && ret >= 0; i++)
            {
                if(loopList->at(i) == NULL)
                    ret = -1;
                else
                    ret |= loopList->at(i)->loop();
            }
            
            return ret;
        };
        
    };
    
}

#endif /*_LOOP_ENGINE_H_*/