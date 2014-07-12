#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "SDL2/SDL.h"

namespace jer
{
    typedef SDL_Renderer Renderer;
    
    class Renderable
    {
    protected:
        Renderer *ren;
        
    public:
        Renderable(Renderer * const r): ren(r) {};
        virtual ~Renderable() {};
        virtual const SUCCESS render() const=0;
    };
}

#endif