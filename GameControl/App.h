#ifndef _APPH_
#define _APP_H_

#include "Declarations.h"
#include "GameLoop.h"
#include "DataManager.h"

namespace jer {

class App: public GameLoop {
  private:
    //TODO: Put list of Gameloops here
  public:
    /// Create an app and call SDL_Init with flags, and create a surface with width, height, and sflags
    App(DataManager * const dataM , const Uint32 flags, const int width, const int height, const int bpp, const Uint32 sflags);
    
    
    /// Calls init() of DataM, then calls run() of DataManager->firstGameLoop(this)
    const int loop() override;
    
    const int render() const override  {};
    
    const int init()  override;
    
    const int cleanup() override;
    
    const EVENT_RESULT exited() override {};
    
    /// Return the DataManager
    DataManager * const dataM();
};

}    
#endif /*APP_H_*/
