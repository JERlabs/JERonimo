#include "App.h"
#include "SDL/SDL.h"

namespace GameControl {

App::App(DataManager * const dataM, const Uint32 flags, const int width, const int height, const int bpp, const Uint32 sflags) :GameLoop(dataM, this) {
  SDL_Init(flags);
  dataM->Display = SDL_SetVideoMode(width, height, bpp, sflags);
  Running = true;
}

const int App::init() {
  if(DataM->init() < 0) {
    Running = false;
    return -1;
  }
  return 0;
}

const int App::loop() {
  if(DataM->firstGameLoop(this)->run() < 0)
    return -1;
  Running = false;
  return 0;
}

const int App::cleanup() {
  SDL_Quit();
}

DataManager* const App::dataM() {
  return DataM;
}

}
