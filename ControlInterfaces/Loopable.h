#ifndef _LOOPABLE_H_
#define _LOOPABLE_H_

#include "Declarations.h"

namespace jer
{
    class Loopable
    {
    public:
        virtual ~Loopable() {};
        virtual const SUCCESS loop()=0;  /// Overload to loop object
    };

}
#endif