#ifndef _APP_H_
#define _APP_H_

#include "SDL/SDL.h"
#include "GameControl.h"
#include "GameLoop.h"
#include "DataManager.h"

namespace GameControl {

class App {
  private:
    /// Pointer to the running GameLoop
    GameLoop* CurrentLoop;
    
    /// The window's SDL surface
    SDL_Surface Surface;
    
    /// DataManager pointer
    DataManager* DataM;
    
    //TODO: Put list of Gameloops here
  public:
    /// Create an app and call SDL_Init with flags, and create a surface with width, height, and sflags
    App(Uint32 flags, int width, int height, int bpp, Uint32 sflags);
    
    /// Start the app with GameLoop loop
    int start(GameLoop* loop, DataManager* dataM);
    
    /// Return the DataManager
    DataManager* dataM();
};

}    
#endif /*APP_H_*/
