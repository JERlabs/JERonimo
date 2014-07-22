#ifndef _LOOP_ENGINE_H_
#define _LOOP_ENGINE_H_

#include "Loopable.h"
#include <vector>

namespace jer
{
    using std::vector;
    
    template<class T>
    class LoopEngine: public virtual Loopable, public vector<T>
    {
    /// LoopEngine, manages a list of Loopable's
    private:
        vector<T> *list;
        
    public:
        LoopEngine(): list(this) {};
        virtual ~LoopEngine() {};
        
    public:
        virtual const SUCCESS loop() // the generic form of the function attempts to use data locality
        {
            SUCCESS ret = 0;
            T *data = list->data();
            int n = list->size();
            for(int i = 0; i < n && ret >= 0; i++)
            {
                ret |= data[i].loop();
            }
            
            return ret;
        };
    };
    
    template<>
    class LoopEngine<Loopable *>: public virtual Loopable, public vector<Loopable *>
    {
    private:
        vector<Loopable *> *list;
        
    public:
        LoopEngine(): list(this) {};
        virtual ~LoopEngine()
        {
            for(auto i = list->begin(); i != list->end(); i++)
            {
                if((*i)->toDie())
                {
                    delete (*i);
                    *i = NULL;
                }
                else
                {
                    (*i)->forgetEngine();
                }
            }
        };
        
    public:
        virtual const SUCCESS loop()  // specific form of the function which has more cache misses but easy polymorphism
        {
            SUCCESS ret = 0;
            for(auto i = list->begin(); i != list->end() && ret >= 0; i++)
            {
                ret |= (*i)->loop();
            }
            
            return ret;
        };
    };
    
    /*
    template<>
    class LoopEngine<Displayable *>: public virtual Loopable, public vector<Displayable *>
    {
    private:
        vector<Displayable *> *list;
        
    public:
        LoopEngine(): list(this) {};
        virtual ~LoopEngine() {};
        
    public:
        virtual const SUCCESS loop() const // specific form of the function which has more cache misses but easy polymorphism
        {
            SUCCESS ret = 0;
            for(auto i = list->begin(); i != list->end() && ret >= 0; i++)
            {
                ret |= (*i)->display();
            }
            
            return ret;
        };
    };
    */
}

#endif /*_LOOP_ENGINE_H_*/