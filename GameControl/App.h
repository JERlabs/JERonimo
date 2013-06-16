#ifndef _APP_H_
#define _APP_H_

#include "GameControl.h"
#include "GameLoop.h"
#include "DataManager.h"

namespace GameControl {

class App: public GameLoop {
  private:
    /// The window's SDL surface
    SDL_Surface Surface;
    
    //TODO: Put list of Gameloops here
  public:
    /// Create an app and call SDL_Init with flags, and create a surface with width, height, and sflags
    App(DataManager * const dataM ,Uint32 flags, int width, int height, int bpp, Uint32 sflags);
    
    
    /// Calls init() of DataM, then calls run() of DataManager->firstGameLoop(this)
    const int loop() override;
    
    const int render() const override {};
    
    const int init() override {};
    
    const int cleanup() override {};
    
    const EVENT_RESULT exited() override {};
    
    /// Return the DataManager
    DataManager* dataM();
};

}    
#endif /*APP_H_*/
