#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "Declarations.h"
namespace jer
{
    class Displayable
    {        
    public:
        virtual ~Displayable() {};
        virtual const SUCCESS display() const=0;   // We'll see about this rule.
    };

}

#endif
