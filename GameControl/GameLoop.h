#ifndef _GAME_LOOP_H_
#define _GAME_LOOP_H_

#include "GameControl.h"
#include "App.h"
#include "Events.h"

namespace GameControl {
// Events is only needed by run to call handleEvent
class GameLoop: protected Events {
  protected:
    /// Pointer to the gameloop to be run next
    GameLoop* NextLoop;
    
    /// Pointer to the App that is running us
    App* CurrentApp;
    
    /// Whether to continue loop execution
    bool Running;
    
    // These methods only need to be called by run()
  protected:
    /// Runs every loop, use for physics stuff
    virtual int const loop()=0;
    
    /// Redraws the screen
    virtual int const render() const=0;
    
    /// Runs once control is given to this loop
    virtual int const init()=0;
    
    /// Runs before control is yielded back to App
    virtual int const cleanup()=0;
  public:
    GameLoop()=delete; // YAY C++11 FEATURE
    GameLoop(const GameLoop&)=delete;
    
    /// Run this loop, accepts an App pointer, returns next gameloop to be run
    GameLoop const * run(App*);
};

}
#endif /*_GAME_LOOP_H_*/
