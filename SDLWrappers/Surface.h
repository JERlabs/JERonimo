#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <memory>

#include "Declarations.h"
#include "ControlInterfaces/FileLoadable.h"
#include "ControlInterfaces/Displayable.h"

namespace jer
{
    using std::shared_ptr;
    
    class
    {
    public:
        void operator()(SDL_Surface * const ptr)
        {
            SDL_FreeSurface(ptr);
        };
        
    } SDL_SURFACE_DELETER;
    
    class Surface: public FileLoadable
    {
    public:
        typedef const SUCCESS (*LOCK_FUNC)(SDL_Surface * const);
        
    private:
        shared_ptr<SDL_Surface> surf;
        
    public:
        virtual ~Surface() {};
        Surface(const string &name): FileLoadable(name), surf(nullptr, SDL_SURFACE_DELETER) {};
        Surface(): surf(nullptr, SDL_SURFACE_DELETER) {};
        Surface(const Surface &other): FileLoadable(other), surf(other.surf) {};
        Surface(SDL_Surface * const s): Surface(shared_ptr<SDL_Surface>(s, SDL_SURFACE_DELETER)) {};
        Surface(const shared_ptr<SDL_Surface> &s): surf(s) {if(surf != nullptr) FileLoadable::load();};
        Surface& operator= (const Surface &other);
        
    public:
        const bool operator== (const Surface &other) const;
        const bool operator!= (const Surface &other) const {return !(*this == other);};
        operator const bool() const {return bool(surf);};
        const bool mustLock() {return SDL_MUSTLOCK(getSurf()) == SDL_TRUE;};
        
    public:
        SDL_Surface * const copy() const {return copy(surf->format);};
        SDL_Surface * const copy(const SDL_PixelFormat *fmt) const;
        const shared_ptr<SDL_Surface> &getSurf() {return surf;};
        const shared_ptr<const SDL_Surface> getSurf() const {return surf;};
        operator const SDL_Surface * const () const {return getSurf().get();};
        operator SDL_Surface * const () {return getSurf().get();};
        SDL_Surface * const operator->() {return getSurf().get();};
        const SDL_Surface * const operator->() const {return getSurf().get();};
        
    public:
        virtual const SUCCESS load() override;
        virtual const SUCCESS unload() override;
        const SUCCESS doLock(LOCK_FUNC func);
        
    private:
        const SUCCESS lock() {return SDL_LockSurface(surf.get());};
        void unlock() {SDL_UnlockSurface(surf.get());};
        const bool isLocked() {return getSurf()->locked;};
    };
}

#endif /*_SURFACE_H_*/