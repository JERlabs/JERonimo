#include "App.h"
#include "SDL/SDL.h"

namespace GameControl {

App::App(Uint32 flags, int width, int height, int bpp, Uint32 sflags) {
  SDL_Init(flags);
  Surface = *SDL_SetVideoMode(width, height, bpp, sflags);
}

int App::start(GameLoop* loop, DataManager* dataM) {
  CurrentLoop = loop;
  DataM = dataM;
  
  bool running = true;
  while(running) {
    CurrentLoop = CurrentLoop->run(this);
    if (CurrentLoop == 0) {
      running = false;
    }
  }
  return 0;
}

}
