#include "Window.h"

namespace jer
{
    const SUCCESS Window::load()
    {
        if(isLoaded())
            return 1;
        
        win = SDL_CreateWindow(name.c_str(), 
                               screenPosition.x(), screenPosition.y(),
                               windowSize.x(), windowSize.y(),
                               flags);
        if(win == NULL)
            return FAILED;
        
        id = SDL_GetWindowID(win);
        
        Loadable::load();
        return SUCCEEDED;
    }
    
    const SUCCESS Window::unload()
    {
        if(isLoaded())
        {
            SDL_DestroyWindow(win);
            win = NULL;
            id = 0;
        }
    }
    
    const string &Window::getName() const
    {
        if(isLoaded())
            return name = SDL_GetWindowTitle(win);
        else
            return name;
    }
    
    const Point<int> &Window::getPosition() const
    {
        if(isLoaded())
            SDL_GetWindowPosition(win, screenPosition.x().getPtr(), screenPosition.y().getPtr());
        return screenPosition;
    }
    
    const Dimensions<int> &Window::getSize() const
    {
        if(isLoaded())
            SDL_GetWindowSize(win, windowSize.x().getPtr(), windowSize.y().getPtr());
        return windowSize;
    }
    
    const Uint32 Window::getFlags() const
    {
        if(isLoaded())
            return flags = SDL_GetWindowFlags(win);
        else
            return flags;
    }
    
    const bool Window::hasFlags(const Uint32 f) const
    {
        return f & getFlags();
    }
    
    void Window::setName(const string& n)
    {
        name = n;
        if(isLoaded())
            SDL_SetWindowTitle(win, name.c_str());
    }
    
    void Window::setPosition(const Point<int> &p)
    {
        screenPosition = p;
        if(isLoaded())
            SDL_SetWindowPosition(win, screenPosition.x(), screenPosition.y());
    }
    
    void Window::setSize(const Dimensions<int> &d)
    {
        windowSize = d;
        if(isLoaded())
            SDL_SetWindowSize(win, windowSize.x(), windowSize.y());
    }
    
    void Window::hide()
    {
        if(isLoaded())
            SDL_HideWindow(win);
        removeInitFlags(SHOWN);
        addInitFlags(HIDDEN);
    }
    
    void Window::show()
    {
        if(isLoaded())
            SDL_ShowWindow(win);
        removeInitFlags(HIDDEN);
        addInitFlags(SHOWN);
    }
    
    void Window::maximize()
    {
        if(isLoaded())
            SDL_MaximizeWindow(win);
        removeInitFlags(MINIMIZED);
        addInitFlags(MAXIMIZED);
    }
    
    void Window::makeFullScreen()
    {
        if(isLoaded())
            SDL_SetWindowFullscreen(win, FULLSCREEN);
        removeInitFlags(FULLSCREEN_DESKTOP);
        addInitFlags(FULLSCREEN);
    }
    
    void Window::makeFullScreenDesktop()
    {
        if(isLoaded())
            SDL_SetWindowFullscreen(win, FULLSCREEN_DESKTOP);
        removeInitFlags(FULLSCREEN);
        addInitFlags(FULLSCREEN_DESKTOP);
    }
    
    void Window::makeWindowed()
    {
        if(isLoaded())
            SDL_SetWindowFullscreen(win, 0);
        removeInitFlags(FULLSCREEN | FULLSCREEN_DESKTOP);
    }
    
    void Window::grabInput()
    {
        if(isLoaded())
        {
            SDL_SetWindowGrab(win, SDL_TRUE);
            getFlags();
        }
        else
        {
            addInitFlags(INPUT_GRABBED);
        }
    }
    
    void Window::releaseInput()
    {
        if(isLoaded())
        {
            SDL_SetWindowGrab(win, SDL_FALSE);
            getFlags();
        }
        else
        {
            removeInitFlags(INPUT_GRABBED);
        }
    }
    
    void Window::setGrab(const bool grab)
    {
        if(grab)
            grabInput();
        else
            releaseInput();
    }
}