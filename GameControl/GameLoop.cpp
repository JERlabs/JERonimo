#include "GameLoop.h"

namespace GameControl {

/**
  Method called by App, passed with a pointer to App, which CurrentApp is
  set to. Then runs init(), then runs loop() and render() until Running
  is false, then runs cleanup().
*/
GameLoop const * GameLoop::run(App* currentApp) {
  CurrentApp = currentApp;
  init();
  while (Running) {
    loop();
    render();
  }
  cleanup();
}

}
