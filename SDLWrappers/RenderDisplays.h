#ifndef _DRAWERS_H_
#define _DRAWERS_H_

#include "Renderer.h"
#include "ControlInterfaces/Displayable.h"

namespace jer
{
    template<class RENDERER>
    class DrawOverRenderer: public RENDERER, public virtual Displayable
    {
    public:
        virtual ~DrawOverRenderer() {};
        /// HardRenderer Constructor
        DrawOverRenderer(const shared_ptr<Window> &w, const bool hardwareAccel=false, const bool vSync=false, const int i=-1):
            RENDERER(w, hardwareAccel, vSync, i) {};
        DrawOverRenderer() {};  /// idgaf        
    public:
        const SUCCESS display() const override
        {
            return this->present();
        };
    };
    
    template<class RENDERER>
    class RedrawRenderer: public RENDERER, public virtual Displayable
    {
    public:
        virtual ~RedrawRenderer() {};
        /// HardRenderer Constructor
        RedrawRenderer(const shared_ptr<Window> &w, const bool hardwareAccel=false, const bool vSync=false, const int i=-1):
            RENDERER(w, hardwareAccel, vSync, i) {};
        RedrawRenderer() {}; /// i said idgaf
    public:
        const SUCCESS display() const override
        {
            if(this->present() < SUCCEEDED)
                return FAILED;
            return this->clear();
        };
    };
}

#endif