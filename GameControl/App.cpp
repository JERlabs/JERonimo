#include "App.h"
#include "SDL/SDL.h"

namespace GameControl {

App::App(DataManager * const dataM, const Uint32 flags, const int width, const int height, const int bpp, const Uint32 sflags) :GameLoop(dataM, this) {
  SDL_Init(flags);
  dataM->Display = SDL_SetVideoMode(width, height, bpp, sflags);
  Running = true;
}

const int App::loop() {
  DataM->init();
  DataM->firstGameLoop(this)->run();
  Running = false;
  return 0;
}

DataManager* const App::dataM() {
  return DataM;
}

}
