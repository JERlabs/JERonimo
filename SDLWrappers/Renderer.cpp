#include "Renderer.h"

namespace jer
{
    const SUCCESS Renderer::unload()
    {
        if(isLoaded())
        {
            SDL_DestroyRenderer(ren);
        }
        return Loadable::unload();
    }
    
    const SUCCESS Renderer::setRenderer(SDL_Renderer * const r)
    {
        if(!isLoaded() && r != NULL)
        {
            ren = r;
            return SUCCEEDED;
        }
        return FAILED;
    }
    
    const SUCCESS Renderer::clear()
    {
        if(isLoaded())
            return SDL_RenderClear(ren);
        return FAILED;
    }
    
    const SUCCESS Renderer::present()
    {
        if(isLoaded())
        {
            SDL_RenderPresent(ren);
            return SUCCEEDED;
        }
    }
    
    const SDL_RendererInfo * const Renderer::getInfo() const
    {
        if(!isLoaded())
            return NULL;
        SDL_GetRendererInfo(ren, &info);
        return &info;
    }
    
    const string Renderer::getName() const
    {
        if(!isLoaded())
            return "";
        return string(getInfo()->name);
    }
    
    const bool Renderer::isSoftwareRenderer() const
    {
        if(!isLoaded())
            return false;
        return bool(getInfo()->flags & SDL_RENDERER_SOFTWARE);
    }
    
    const bool Renderer::isHardwareAccelerated() const
    {
        if(!isLoaded())
            return false;
        return bool(getInfo()->flags & SDL_RENDERER_ACCELERATED);
    }
    
    const bool Renderer::presentsVSync() const
    {
        if(!isLoaded())
            return false;
        return bool(getInfo()->flags & SDL_RENDERER_PRESENTVSYNC);
    }
    
    const bool Renderer::doesRenderToTexture() const
    {
        if(!isLoaded())
            return false;
        return bool(getInfo()->flags & SDL_RENDERER_TARGETTEXTURE);
    }
    
    const Uint32 Renderer::getNumTextureFormats() const
    {
        if(!isLoaded())
            return 0;
        return getInfo()->num_texture_formats;
    }
    
    const Uint32 Renderer::getTextureFormat(const Uint32 n) const
    {
        if(n >= getNumTextureFormats())
            return -1;
        return info.texture_formats[n];
    }
    
    const Dimensions<int> Renderer::getMaxTextureSize() const
    {
        getInfo();
        return Dimensions<int>(info.max_texture_width, info.max_texture_height);
    }
    
    const Dimensions<int> Renderer::getOutputSize() const
    {
        Dimensions<int> ret;
        if(isLoaded())
           if(SDL_GetRendererOutputSize(ren, ret.x().getPtr(), ret.y().getPtr()) < 0)
               return Dimensions<int>(-1, -1);
        return ret;
    }
    
    const Dimensions<int> Renderer::getLogicalSize() const
    {
        Dimensions<int> ret(-1, -1);
        if(isLoaded())
            SDL_RenderGetLogicalSize(ren, ret.x().getPtr(), ret.y().getPtr());
        return ret;
    }
    
    SDL_RendererInfo * const Renderer::initInfo()
    {
        if(!isLoaded())
            return &info;
        else
            return NULL;
    }
}