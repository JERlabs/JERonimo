#include "FPSManager.h"

namespace jer
{
    const SUCCESS FPSManager::loop()
    {
        if(SDL_GetTicks() > (cycles+1)*millisecondsPerCycle)
        {
            cycles++;
            lagMultiplier = 1000.0*double(cycleFrames)/double(millisecondsPerCycle)/double(targetFPS);
            cycleFrames = 0;
        }
        
        frames++;
        cycleFrames++;
        return SUCCEEDED;
    }
}