#include "App.h"
#include "SDL/SDL.h"

namespace GameControl {

App::App(DataManager * const dataM, Uint32 flags, int width, int height, int bpp, Uint32 sflags) :GameLoop(dataM, this) {
  SDL_Init(flags);
  Surface = *SDL_SetVideoMode(width, height, bpp, sflags);
  Running = true;
}

const int App::loop() {
  DataM->init();
  DataM->firstGameLoop(this)->run();
  Running = false;
  return 0;
}

DataManager* App::dataM() {
  return DataM;
}

}
