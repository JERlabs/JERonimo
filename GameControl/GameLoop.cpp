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

GameLoop::GameLoop(const GameLoop& other): DataM(other.DataM), Parent(other.Parent) {
}
/**
  Method called by App, passed with a pointer to App, which CurrentApp is
  set to. Then runs init(), then runs loop() and render() until Running
  is false, then runs cleanup(). Any events are polled after render(), and
  passed to their respective methods by handleEvents
*/
int const GameLoop::run() {
  SDL_Event event;
  init();
  while (Running && (DataM==NULL? true: DataM->running())) {
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
