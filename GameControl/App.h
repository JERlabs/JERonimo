#ifndef _APP_H_
#define _APP_H_

#include "GameControl.h"
#include "GameLoop.h"
#include "DataManager.h"

namespace GameControl {

class App: public GameLoop {
  private:
    //TODO: Put list of Gameloops here
  public:
    /// Create an app and call SDL_Init with flags, and create a surface with width, height, and sflags
    App(DataManager * const dataM , const Uint32 flags, const int width, const int height, const int bpp, const Uint32 sflags);
    
    /// Calls init() of DataM, then calls run() of DataManager->firstGameLoop(this)
    virtual const int loop() override;
    
    /// Return the DataManager
    DataManager * const dataM();
};

}    
#endif /*APP_H_*/
