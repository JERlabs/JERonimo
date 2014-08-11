#ifndef _LOADABLE_H_
#define _LOADABLE_H_

#include <memory>

#include "Declarations.h"

namespace jer
{
    using std::shared_ptr;
    
    
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
    
    inline const SUCCESS Loadable::load()
    {
        loaded = true;
        return SUCCEEDED;
    }
    
    inline const SUCCESS Loadable::unload()
    {
        loaded = false;
        return SUCCEEDED;
    }
    
    class LoadWrapper: public shared_ptr<Loadable>, public Loadable
    {
    public:
        virtual ~LoadWrapper() {if(get()->isLoaded()) get()->unload();};
        LoadWrapper(Loadable * const comp=nullptr): shared_ptr<Loadable>(comp) {};
        LoadWrapper(const shared_ptr<Loadable>& other): shared_ptr<Loadable>(other) {};
        
    public:
        virtual const SUCCESS load() override 
        {
            if(get())
            {
                Loadable::load();
                return get()->load();
            }
            return FAILED;
        };
        virtual const SUCCESS unload() override 
        {
            Loadable::unload();
            if(get())
            {
                return get()->unload();
            }
            return FAILED;            
        };
    };

}
#endif
