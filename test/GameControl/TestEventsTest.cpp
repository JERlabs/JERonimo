#include "GameControl/TestEvents.h"
#include "GameControl/App.h"
#include "GameControl/DataManager.h"

using namespace GameControl;

class TestEventsDataMan: public DataManager {
public:
  const int init() {
    Running = true;
    currentGL = NULL;
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    SDL_EnableUNICODE(1);
  };
  
  GameLoop * const firstGameLoop(App *parent) {
    if(currentGL == NULL)
      currentGL = new TestEvents(this, parent);
    return currentGL;
  };
};


int main(int argc, char *argv[]) {
  App myApp(new TestEventsDataMan, SDL_INIT_EVERYTHING, 640, 480, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE);
  myApp.run();
  return 0;
}
