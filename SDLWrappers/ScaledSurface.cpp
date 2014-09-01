#include "ScaledSurface.h"

namespace jer
{
    ScaledSurface& ScaledSurface::operator= (const ScaledSurface &other)
    {
        this->operator=(other);
        resize(other.getDim());
    }
    const SUCCESS ScaledSurface::load()
    {
        const SUCCESS ret = Surface::load();
        return ret | resize();
    }
    
    const SUCCESS ScaledSurface::resize(const Dimensions<int> &d)
    {
        size = d;
        if(isLoaded())
        {
            if(getDim() != size)
            {
                Surface old(*this);
                Surface::operator=(SDL_CreateRGBSurface(0, size.x(), size.y(), 
                                                   (*this)->format->BitsPerPixel, 
                                                   (*this)->format->Rmask, (*this)->format->Gmask, (*this)->format->Bmask, (*this)->format->Amask));
                if(getSurf() == nullptr)
                    return FAILED;
                if(SDL_BlitScaled(old, NULL, *this, NULL) < SUCCEEDED)
                {
                    Surface::FileLoadable::unload();
                    return FAILED;
                }
                else
                    return SUCCEEDED;
            }
        }
        
        return SUCCEEDED;
    }
}