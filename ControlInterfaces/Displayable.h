#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "Loopable.h"
namespace jer
{
    class Displayable: public Loopable
    {        
    public:
        virtual ~Displayable() {};
        Displayable(LoopEngine<Loopable *> * const engine): Loopable(engine) {};
        Displayable() {};
        
    public:
        virtual const SUCCESS display() const=0;   // We'll see about this rule.
        
    private:
        const SUCCESS loop() {return display();};  // Displayable inherits a lot of properties in Loopable but it has a different mindset
    };

}

#endif
