#ifndef _CONTROL_DECLARATIONS_H_
#define _CONTROL_DECLARATIONS_H_

#include <stdlib.h>

#ifdef DEBUG
#include <iostream>  // Used to log
#endif

namespace jer
{
    typedef char SUCCESS;
    enum {FAILED=-1, SUCCEEDED=0, LOGGED=1};
    class Loadable;
    class Loopable;
    class Displayable;
    class PriorityInterface;
    class PriorityElement;
    template<class T> class GameList;
    template<class T> class SortList;
    template<class T, class MAP_TYPE> class MapList;
    template<class T, class LIST_TYPE> class LoopEngine;
    template<class T, class LIST_TYPE> class DataManager;
    template<class T, class LIST_TYPE> class DisplayQueue;
	class Runnable;
    class SimpleRunnable;
    class CompositeRunnable;
    // if the error was logged at a narrower scope then the function returns 1
}

#endif /*_CONTROL_DECLARATIONS_H_*/