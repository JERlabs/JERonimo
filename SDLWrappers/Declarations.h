#ifndef _SDL_WRAPPER_DECLARATIONS_H_
#define _SDL_WRAPPER_DECLARATIONS_H_

#include "SDL2/SDL.h"
#include "ControlInterfaces/Declarations.h"

namespace jer
{
	class App;   	/// Singleton class which encapsulates the SDL subsystem starts and quits on destruction, inherits Loadable and Runnable
}

#endif /*_SDL_WRAPPER_DECLARATIONS_H_*/