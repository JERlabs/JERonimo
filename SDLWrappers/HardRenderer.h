#ifndef _HARD_RENDERER_H_
#define _HARD_RENDERER_H_

#include <memory>

#include "Renderer.h"
#include "Window.h"

namespace jer
{
    class HardRenderer: public Renderer
    {
    private:
        shared_ptr<Window> win;
        int index;
        
    public:
        virtual ~HardRenderer() {if(isLoaded()) this->unload();};
        HardRenderer(const shared_ptr<Window> &w, const bool hardwareAccel=false, const bool vSync=false, const int i=-1);
        HardRenderer(const bool hardwareAccel=false, const bool vSync=false, const int i=-1);
        
    public:
        const SUCCESS load() override;
        
    public:
        shared_ptr<Window> getWin();
        const Window &getWin() const;
        
    public:
        const int getIndex() const;
        void initIndex(const int i);
        void initHardwareAccel(const bool accel);
        void initPresentVSync(const bool vsync);
    };
}

#endif /*_HARD_RENDERER_H_*/