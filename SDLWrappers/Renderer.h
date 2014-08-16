#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Declarations.h"
#include "Window.h"
#include "ControlInterfaces/Loadable.h"

namespace jer
{
    class Renderer: public Loadable
    {
    private:
        SDL_Renderer *ren;
        mutable SDL_RendererInfo info;
        
    public:
        virtual ~Renderer() {if(isLoaded()) this->unload();};
        Renderer(): ren(NULL) {};
        
    public:
        virtual const SUCCESS load()=0;
        virtual const SUCCESS unload() override;
        
    public:
        const SDL_Renderer * const getRenderer() const {return ren;};
        SDL_Renderer * const getRenderer() {return ren;};
        
    protected:
        const SUCCESS setRenderer(SDL_Renderer * const r);
        
    protected:
        const SUCCESS clear() const;
        const SUCCESS present() const;
        const SDL_RendererInfo * const getInfo() const;
        SDL_RendererInfo * const initInfo();
        
    public:
        const string getName() const;
        const bool isSoftwareRenderer() const;
        const bool isHardwareAccelerated() const;
        const bool presentsVSync() const;
        const bool doesRenderToTexture() const;
        const Uint32 getNumTextureFormats() const;
        const Uint32 getTextureFormat(const Uint32 n) const;
        const Dimensions<int> getMaxTextureSize() const;
        
        const Dimensions<int> getOutputSize() const;
        const Dimensions<int> getLogicalSize() const;
    };
}


#endif /*_RENDERER_H_*/ 