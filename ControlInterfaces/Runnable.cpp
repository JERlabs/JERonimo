#include "Runnable.h"

namespace jer {

const SUCCESS SimpleRunnable::run() {
  if((status = load()) < SUCCEEDED)
    return status;
  
  running = true;
  while (running) {
    if((status = loop()) < SUCCEEDED)
      break;
    if((status = display()) < SUCCEEDED)
      break;
  }
  
  status = unload();
  return status;
}

}
