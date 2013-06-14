#include "DataManager.h"
#include "GameLoop.h"

namespace GameControl {

GameLoop::GameLoop(DataManager * const dataM, GameLoop * const parent) {
  DataM = dataM;
  Parent = parent;
}

GameLoop::GameLoop(DataManager &dataM, GameLoop &parent) {
  DataM = &dataM;
  Parent = &parent;
}
/**
  Method called by App, passed with a pointer to App, which CurrentApp is
  set to. Then runs init(), then runs loop() and render() until Running
  is false, then runs cleanup(). Any events are polled after render(), and
  passed to their respective methods by handleEvents
*/
<<<<<<< HEAD
GameLoop * const GameLoop::run(App* const currentApp) {
  CurrentApp = currentApp;
  NextLoop = this;
=======
int const GameLoop::run() {
>>>>>>> 6e8380cbf70e9e92943c65b04cce5c8ae166932b
  SDL_Event event;
  init();
  while (Running) {
    loop();
    render();
    while(SDL_PollEvent(&event)) {
      handleEvent(&event);
    }
  }
  cleanup();
  return Status;
}

}
