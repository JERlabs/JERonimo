#include "App.h"

namespace jer
{
	App App::app;
	
	const SUCCESS App::load()
	{
		if(isLoaded())
			return FAILED;
			
		SUCCESS ret;
		if((ret = SDL_Init(initFlags)) >= SUCCEEDED)
			Loadable::load();
		
		return ret;
	}
	
	const SUCCESS App::unload()
	{
		if(isLoaded())
		{
			SDL_Quit();
			Loadable::unload();
		}
		return status;
	}
	
	const SUCCESS App::run()
	{
		if(mainApp == NULL)
			return FAILED;
		
		if((status = load()) < SUCCEEDED)
			return status;
		
		running = true;
		status = mainApp->run();
		running = false;
		
		status = unload();
		return status;
	}
	
	const SUCCESS App::loadSubSystem(const Uint32 flags)
	{
		if(isLoaded())
		{
			if(SDL_WasInit(flags) != flags)
				return SDL_InitSubSystem(flags);
		}
		else
		{
			initFlags |= flags;
		}
		
		return SUCCEEDED;
	}
}

