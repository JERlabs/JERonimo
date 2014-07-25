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
        Loadable(): loaded(false) {};
        virtual ~Loadable() {};

        virtual const SUCCESS load()=0;  /// Overload to load object
        virtual const SUCCESS unload()=0;  /// Overload to clean up object
        const bool isLoaded() const {return loaded;};  /// Used to check the state of the loadable object
    };
    
    const SUCCESS Loadable::load()
    {
        loaded = true;
        return SUCCEEDED;
    }
    
    const SUCCESS Loadable::unload()
    {
        loaded = false;
        return SUCCEEDED;
    }

}
#endif