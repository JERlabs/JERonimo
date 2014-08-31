#ifndef _SDL_WRAPPER_DECLARATIONS_H_
#define _SDL_WRAPPER_DECLARATIONS_H_

extern "C"
{
	#include "SDL.h"
    #include "SDL_image.h"
}
#include "ControlInterfaces/Declarations.h"

namespace jer
{
	class App;   	
    /// Singleton class which encapsulates the SDL subsystem starts and quits on destruction, inherits Loadable and Runnable.
	
    template<class IMPLEMENTATION> class Logger;
    /// Templatized subclass of ControlInterface Loadable/Loopable/Displayable Implementations which logs errors from SDL.
    
    class Window;
    /// Wrapper class for SDL_Window, supports all get and set functions on the window. Sub class of Loadable
    
    class Renderer;
    /// Wrapper class for SDL_Renderer, supports all get and set functions on renderer. Sub class of Loadable.
    
    class HardRenderer;
    /// Subclass of Renderer whose load function loads it as a Hardware renderer (SDL_CreateRenderer).
    
    class SoftRenderer;
    /// Subclass of Renderer whose load function loads is as a software renderer (SDL_CreateSoftRenderer).
    
    template<class RENDERER> class DrawOverRenderer;
    /// Template class for Renderers which present the renderer, without clearing it after each frame. Subclass of Displayable.
    
    template<class RENDERER> class RedrawRenderer;
    /// Template class for Renderers which present the renderer, and then clear the renderer on each frame. Subclass of Displayable.
    
    class Events;
    /// Interface class containing static functions for global event handling and virtual member functions called by handleEvent overridable by subclasses to define event behavior
    
    class EventLogger;
    /// Outputs text describing what event was thrown, good for testing input.
    
    class Surface;
    /// FileLoadable and Drawable which hold an SDL_Surface. It handles the loading and drawing of and SDL_Surface
    
    class ClosedSurface;
    /// Subclass of private Surface, it has the same functionality as Surface except the user cannot gain non-const access to the contained Surface
}

#endif /*_SDL_WRAPPER_DECLARATIONS_H_*/