#ifndef _LOOPABLE_H_
#define _LOOPABLE_H_

#include "Declarations.h"

namespace jer
{
    class Loopable
    {   
    public:
        Loopable() {};
        virtual ~Loopable() {};
        virtual const SUCCESS loop()=0;  /// Override to loop object
    };

}
#endif