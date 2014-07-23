#ifndef _LOADABLE_H_
#define _LOADABLE_H_

#include "Declarations.h"

namespace jer
{
    class Loadable
    {
    private:
        bool loaded;
        
    public:
        Lodable(): loaded(false) {};
        virtual ~Loadable() {};

        virtual const SUCCESS load()=0 {loaded=true; return SUCCEEDED;};  /// Overload to load object
        virtual const SUCCESS unload()=0 {loaded=false; return SUCCEEDED;};  /// Overload to clean up object
        const bool isLoaded() {return loaded;};  /// Used to check the state of the loadable object
    };

}
#endif