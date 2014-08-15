#include "HardRenderer.h"

namespace jer
{
    HardRenderer::HardRenderer(const shared_ptr<Window> &w, const bool hardwareAccel, const bool vSync, const int i):
        win(w), index(i)
    {
        auto inf = initInfo();
        if(inf == NULL)
            return;
        inf->flags = 0;
        if(hardwareAccel)   inf->flags |= SDL_RENDERER_ACCELERATED;
        if(vSync)           inf->flags |= SDL_RENDERER_PRESENTVSYNC;
    }
    
    HardRenderer::HardRenderer(const bool hardwareAccel, const bool vSync, const int i):
        HardRenderer(shared_ptr<Window>(new Window(App::GetApp().getTitle(), 
                                Point<int>(0,0), Dimensions<int>(-1, -1), 
                                Window::FULLSCREEN_DESKTOP | Window::SHOWN)), 
                     hardwareAccel, vSync, i)
    {
    }
    
    const SUCCESS HardRenderer::load()
    {
        if(isLoaded())
            return SUCCEEDED;
        
        if(win->load() < SUCCEEDED || initInfo() == NULL)
            return FAILED;
        
        if(setRenderer(SDL_CreateRenderer(win->getWindow(), index, initInfo()->flags)) < SUCCEEDED)
            return FAILED;
        
        SDL_SetRenderDrawColor(getRenderer(), 0, 0, 0, 0);
        
        Loadable::load();
        getInfo();
    }
    
    shared_ptr<Window> HardRenderer::getWin()
    {
        return win;
    }
    
    const Window &HardRenderer::getWin() const
    {
        return *win;
    }
    
    const int HardRenderer::getIndex() const
    {
        return index;
    }
    
    void HardRenderer::initIndex(const int i)
    {
        if(!isLoaded())
            index = i;
    }
    
    void HardRenderer::initHardwareAccel(const bool accel)
    {
        if(isLoaded())
            return;
        if(accel) 
            initInfo()->flags |= SDL_RENDERER_ACCELERATED;
        else
            initInfo()->flags &= ~Uint32(SDL_RENDERER_ACCELERATED);
    }
    
    void HardRenderer::initPresentVSync(const bool vsync)
    {
        if(isLoaded())
            return;
        if(vsync)
            initInfo()->flags |= SDL_RENDERER_PRESENTVSYNC;
        else
            initInfo()->flags &= ~Uint32(SDL_RENDERER_PRESENTVSYNC);
    }
    
}