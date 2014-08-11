#include "Logger.h"

namespace jer
{
    const SUCCESS log(const SUCCESS error, const string& caller)
    {
        if(error < SUCCEEDED)
        {
            const char *sdlError = SDL_GetError();
            SDL_ClearError();
            if(*sdlError != '\0')
                std::cerr<<"SDL Error called from "<<caller<<": "<<sdlError<<std::endl;
            else
                std::cerr<<"Non SDL Error called from "<<caller<<std::endl;
        }
        
        return error;
    }
}