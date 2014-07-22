#include "LoopEngine.h"
#include <algorithm>

namespace jer
{
    void Loopable::addSelfToEngine(LoopEngine<Loopable *> * const engine)
    {
        assignEngine(engine);
        
        if(list)
        {
            list->push_back(this);
        }
    }
    
    void Loopable::removeSelfFromEngine()
    {
        if(list)
        {
            if(references > 1)
            {
                references--;
                list->erase(std::remove(list->begin(), list->end(), this), list->end());
            }
            list = NULL;
        }
    }
    
    void Loopable::assignEngine(LoopEngine<Loopable *> * const engine)
    {
        if(engine == this)
            return;
        
        list = engine;
        if(list)
            references++;
    }
    
    void Loopable::forgetEngine()
    {
        if(list)
            list = NULL;
        
        references--;
    }
    
}