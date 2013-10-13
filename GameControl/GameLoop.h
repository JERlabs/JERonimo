#ifndef _GAME_LOOP_H_
#define _GAME_LOOP_H_

#include "GameControl.h"
#include "DataManager.h"
#include "Events.h"

namespace GameControl {
// Events is only needed by run to call handleEvent
class GameLoop: protected Events {
  protected:
    /// Return Status of the gameloop's run function
    int Status;
    
    /// Pointer to the DataManager that contains the game data.
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
    
    GameLoop(const GameLoop&);
    
    /// Run this loop, accepts an App pointer, returns next gameloop to be run
    int const run();
};

}
#endif /*_GAME_LOOP_H_*/
