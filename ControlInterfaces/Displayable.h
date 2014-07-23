#ifndef _DISPLAYABLE_H_
#define _DISPLAYABLE_H_

#include "Declarations.h"
namespace jer
{
    class Displayable
    {        
    public:
        virtual ~Displayable() {};
        Displayable() {};
        
    public:
        virtual const SUCCESS display() const=0;   // We'll see about this const rule.
    };

}

#endif
