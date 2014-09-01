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
            if(IMG_Init(imgFlags) == imgFlags)
                Loadable::load();
            else
                ret = -1;
		
		return ret;
	}
	
	const SUCCESS App::unload()
	{
		if(isLoaded())
		{
			SDL_Quit();
            IMG_Quit();
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
	
	const SUCCESS App::loadIMGSubSystem(const Uint32 flags)
    {
        if(isLoaded())
        {
            if(IMG_Init(0) != flags)
                return IMG_Init(flags) == flags? 0:-1;
        }
        else
        {
            imgFlags |= flags;
        }
        
        return SUCCEEDED;
    }
    
    const SUCCESS App::loadFileType(const string &fileName)
    {
        SDL_RWops *rwop;
        rwop = SDL_RWFromFile(fileName.c_str(), "rb");
        if(IMG_isJPG(rwop))
            return loadJPG();
        else if(IMG_isPNG(rwop))
            return loadPNG();
        else if(IMG_isTIF(rwop))
            return loadTIF();
        else if(IMG_isGIF(rwop) || IMG_isBMP(rwop) || IMG_isCUR(rwop) || IMG_isICO(rwop) || IMG_isLBM(rwop) ||
                IMG_isLBM(rwop) || IMG_isPCX(rwop) || IMG_isPNM(rwop) || IMG_isXCF(rwop) || IMG_isXPM(rwop) || IMG_isXV(rwop))
            return SUCCEEDED;
        else
            return FAILED;            
    }
}