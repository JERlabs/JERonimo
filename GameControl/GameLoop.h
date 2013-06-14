#ifndef _GAME_LOOP_H_
#define _GAME_LOOP_H_

#include "GameControl.h"
#include "DataManager.h"
#include "Events.h"

namespace GameControl {
// Events is only needed by run to call handleEvent
class GameLoop: protected Events {
  protected:
    /// Pointer to the gameloop to be run next
    int Status;
    
    /// Pointer to the App that is running us
    DataManager* DataM;
    
    /// The GameLoop that called run() on this one
    GameLoop* Parent;
    
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
    /// Initialize GameLoop with DataManager dataM, and parent GameLoop parent passed as pointers
    GameLoop(DataManager * const dataM, GameLoop * const parent);
    
    /// Initialize GameLoop with DataManager dataM, and parent GameLoop parent passed by reference
    GameLoop(DataManager &dataM, GameLoop &parent);
    
    /// Run this loop, accepts an App pointer, returns next gameloop to be run
<<<<<<< HEAD
    GameLoop * const run(App* const );
=======
    int const run();
>>>>>>> 6e8380cbf70e9e92943c65b04cce5c8ae166932b
};

}
#endif /*_GAME_LOOP_H_*/
