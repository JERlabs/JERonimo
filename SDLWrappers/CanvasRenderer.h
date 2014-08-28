#ifndef _CANVAS_RENDERER_H_
#define _CANVAS_RENDERER_H_

#include "Drawable.h"
#include "Renderer.h"

namespace jer
{
    template<class RENDERER>
    class CanvasRenderer: public RENDERER, public Drawable
    {
    private:
        SDL_Renderer *getRen() const {return Renderer::mutateRenderer();};
        
    public:
        virtual ~CanvasRenderer() {};
        /// HardRenderer Constructor
        CanvasRenderer(const shared_ptr<Window> &w, const bool hardwareAccel=false, const bool vSync=false, const int i=-1):
            RENDERER(w, hardwareAccel, vSync, i) {};
        CanvasRenderer() {};
        
    public:
        virtual const SUCCESS setColor(const Color& c) override
        {
            return SDL_SetRenderDrawColor(getRen(), c.R(), c.G(), c.B(), c.A());
        };
        
        virtual const Color getColor() const override
        {
            Color ret;
            SDL_GetRenderDrawColor(getRen(), &ret.R(), &ret.G(), &ret.B(), &ret.A());
            return ret;
        };
        
        virtual const SUCCESS setBlendMode(const Uint8 mode) override
        {
            return SDL_SetRenderDrawBlendMode(getRen(), SDL_BlendMode(mode));
        };
        
        virtual const Uint8 getBlendMode() const override
        {
            SDL_BlendMode ret;
            SDL_GetRenderDrawBlendMode(getRen(), &ret);
            return ret;
        };
        
        virtual const SUCCESS drawPoint(const Point<int> &p) override
        {
            return SDL_RenderDrawPoint(getRen(), p.x(), p.y());
        };
        
        virtual const SUCCESS drawLine(const Line<int> &line) override
        {
            return SDL_RenderDrawLine(getRen(), line.p1.x(), line.p1.y(), line.p2.x(), line.p2.y());
        };
        
        virtual const SUCCESS drawRect(const Rectangle<int> &rect) override
        {
            SDL_Rect rec(rect);
            return SDL_RenderDrawRect(getRen(), &rec);
        };
        
        virtual const SUCCESS fillRect(const Rectangle<int> &rect) override
        {
            SDL_Rect rec(rect);
            return SDL_RenderFillRect(getRen(), &rec);
        };
    };
}


#endif /*_CANVAS_RENDERER_H_*/