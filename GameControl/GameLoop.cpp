#include "GameLoop.h"

namespace GameControl {

/**
  Method called by App, passed with a pointer to App, which CurrentApp is
  set to. Then runs init(), then runs loop() and render() until Running
  is false, then runs cleanup(). Any events are polled after render(), and
  passed to their respective methods by handleEvents
*/
GameLoop * const GameLoop::run(App* const currentApp) {
  CurrentApp = currentApp;
  NextLoop = this;
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
  return NextLoop;
}

}
