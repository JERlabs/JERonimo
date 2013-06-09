#ifndef _GAME_CONTROL_H_
#define _GAME_CONTROL_H_

#include <SDL.h>

#include "Point.h"
#include "Vector.h"
#include "Velocity.h"

namespace GameControl {
  class Events;   //handles events and allows GameLoop to inherit every event as a overloadable function
  class GameLoop; //inherites Events and handles the control flow. Classes which inherit overload the various parts of its standard loop
  class App;      //controls which gameloop is being run, initializes SDL

}







#endif /*_GAME_CONTROL_H_*/