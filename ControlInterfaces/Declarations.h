#ifndef _GAME_ELEMENTS_H_
#define _GAME_ELEMENTS_H_

#include <stdlib.h>

#ifdef DEBUG
#include <iostream>  // Used to log
#endif

namespace jer
{
    typedef char SUCCESS;
    enum {FAILURE=-1, SUCCESS=0, LOGGED=1};
    // if the error was logged at a narrower scope then the function returns 1
}

#endif