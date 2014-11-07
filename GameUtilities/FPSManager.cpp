#include "FPSManager.h"

namespace jer
{
    const SUCCESS FPSManager::loop()
    {
        if(SDL_GetTicks() > (cycles+1)*millisecondsPerCycle)
        {
            cycles++;
            lagMultiplier = double(targetFPS)/(1000.0*double(cycleFrames)/double(millisecondsPerCycle));
            cycleFrames = 0;
        }
        
        frames++;
        cycleFrames++;
        return SUCCEEDED;
    }
}