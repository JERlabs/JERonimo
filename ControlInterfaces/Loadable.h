#ifndef _LOADABLE_H_
#define _LOADABLE_H_

#include "Declarations.h"

namespace jer
{
    class Loadable
    {
    public:
        virtual ~Loadable()
        {
#ifndef DEBUG
            unload();
#else
            if(unload() < 0)
                std::cerr<<"Loadable::unload("<<this<<") returned failure"<<std::endl;
#endif
        };
        virtual const SUCCESS load()=0;  /// Overload to load object
        virtual const SUCCESS unload()=0;  /// Overload to clean up object
    };

}
#endif