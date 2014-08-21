#ifndef _SDL_WRAPPER_DECLARATIONS_H_
#define _SDL_WRAPPER_DECLARATIONS_H_

extern "C"
{
	#include "SDL.h"
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
    
    class Mouse;
    /// Class which maintains the current state of mice the program receives input from, by ID. Not instantiable outside the scope of the class
    
}

#endif /*_SDL_WRAPPER_DECLARATIONS_H_*/