#include "GameLoop.h"

namespace jer {

const SUCCESS GameLoop::run() {
  if((status = load()) < SUCCEEDED)
    return status;
  
  running = true;
  while (running) {
    if((status = loop()) < 0)
      break;
    if((status = display()) < 0)
      break;
  }
  
  status = unload();
  return status;
}

}
