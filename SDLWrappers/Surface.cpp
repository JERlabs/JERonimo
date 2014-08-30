#include "Surface.h"

namespace jer
{
    Surface& Surface::operator= (const Surface &other)
    {
        if(&other != this && *this != other)
        {
            if(*this)
            {
                Surface cop(other);
                surf.swap(cop.surf);
            }
            
            setFile(other.getFile());
            
            if(other.isLoaded())
                FileLoadable::load();
            else
                FileLoadable::unload();
        }
        
        return *this;
    }
    
    const bool Surface::operator== (const Surface &other) const
    {
        if(isLoaded() && other.isLoaded())
            return surf == other.surf;
        else if(!isLoaded() && !other.isLoaded())
            return getFile() == other.getFile();
        else
            return false;
    }
    
    SDL_Surface * const Surface::copy(const SDL_PixelFormat *fmt) const
    {
        if(*this)
            return SDL_ConvertSurface(surf.get(), fmt, 0);
        return NULL;
    }
    
    const SUCCESS Surface::load()
    {
        if(isLoaded())
            return 1;
        surf.reset(IMG_Load(getFile().c_str()));
        if(surf == nullptr)
            return FAILED;
        FileLoadable::load();
        return SUCCEEDED;
    }
    
    const SUCCESS Surface::unload()
    {
        if(isLoaded())
            surf.reset();
        FileLoadable::unload();
        return SUCCEEDED;
    }
    
    const SUCCESS Surface::doLock(LOCK_FUNC func)
    {
        if(mustLock()) lock();
        const SUCCESS ret = func(surf.get());
        if(mustLock()) unlock();
        return ret;
    }
    
}