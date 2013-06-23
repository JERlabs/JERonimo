#ifndef _GAME_CONTROL_H_
#define _GAME_CONTROL_H_

#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include "SDL/SDL.h"

#include "Space2D/Point.h"
#include "Space2D/Vector.h"
#include "Space2D/Velocity.h"

#define NUM_KEYS 133

enum {MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE, NUM_MOUSE_BUTTON};

using std::bitset;
using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace GameControl {
  class Events;     ///< handles events and allows GameLoop to inherit every event as an overloadable function
  class GameLoop;   ///< inherites Events and handles the control flow. Classes which inherit overload the various parts of its standard loop
  class App;        ///< controls which gameloop is being run, initializes SDL
  class DataManager;///< Lets gameloops store and share data
  //This comment is here for no purpose. Recent git push was unsuccessful, so by making this change, it will have to push changes again,
  //without claiming things are up to date.

}







#endif /*_GAME_CONTROL_H_*/
