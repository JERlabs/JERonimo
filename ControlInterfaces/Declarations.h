#ifndef _CONTROL_DECLARATIONS_H_
#define _CONTROL_DECLARATIONS_H_

#include <stdlib.h>

#ifdef DEBUG
#include <iostream>  // Used to log
#endif

namespace jer
{
    typedef char SUCCESS;
    enum {FAILURE=-1, SUCCEEDED=0, LOGGED=1};
    class Loadable;
    class Loopable;
    class Displayable;
    class DataManager;
    template<class T> class PriorityElement;
    template<class T> class ListElement;
    template<class T, bool PRIORITY = false> class GameList;
    template<class T, bool PRIORITY = false> class LoopEngine;
    // if the error was logged at a narrower scope then the function returns 1
}

#endif /*_CONTROL_DECLARATIONS_H_*/