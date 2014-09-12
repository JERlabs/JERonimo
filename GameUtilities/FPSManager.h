#ifndef _FPS_MANAGER_H_
#define _FPS_MANAGER_H_

#include "SDLWrappers/Declarations.h"
#include "ControlInterfaces/Loopable.h"

namespace jer
{
    class FPSManager: public Loopable
    {
    private:
        /// Constructor variables
        unsigned short targetFPS;
        unsigned int millisecondsPerCycle;
        
        unsigned long long frames;
        
        unsigned int cycleFrames;
        unsigned int cycles;
        
        double lagMultiplier;
        
    public:
        FPSManager(const unsigned short target=30, const unsigned short milsPerCyc=200): targetFPS(target), millisecondsPerCycle(milsPerCyc), cycleFrames(0), cycles(0), lagMultiplier(1.0) {};
        
    public:
        const unsigned short getTargetFPS() const {return targetFPS;};
        const unsigned int getMillisecondsPerCycle() const {return millisecondsPerCycle;};
        
        const unsigned long long getFrames() const {return frames;};
        
        void setTargetFPS(const unsigned short targ) {targetFPS = targ;};
        void setMillisecondsPerCycle(const unsigned int mils) {millisecondsPerCycle = mils;};
        
        const double getLagMultiplier() const {return lagMultiplier;};
        
    public:
        const SUCCESS loop() override;
        
    };
}


#endif /*_FPS_MANAGER_H_*/