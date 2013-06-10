#ifndef _GAME_CONTROL_H_
#define _GAME_CONTROL_H_

#include <SDL.h>

#include "Point.h"
#include "Vector.h"
#include "Velocity.h"

namespace GameControl {
  class Events;   /// handles events and allows GameLoop to inherit every event as an overloadable function
  class GameLoop; /// inherites Events and handles the control flow. Classes which inherit overload the various parts of its standard loop
  class App;      /// controls which gameloop is being run, initializes SDL
  //This comment is here for no purpose. Recent git push was unsuccessful, so by making this change, it will have to push changes again,
  //without claiming things are up to date.

}







#endif /*_GAME_CONTROL_H_*/