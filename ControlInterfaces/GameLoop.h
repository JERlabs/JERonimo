#ifndef _GAME_LOOP_H_
#define _GAME_LOOP_H_

#include "Declarations.h"
#include "Loopable.h"
#include "Displayable.h"
#include "Loadable.h"

namespace jer {
// Events is only needed by run to call handleEvent
class GameLoop: public Loadable, public Loopable, public Displayable {
protected:
    /// Return Status of the gameloop's run function
    int status;
    
    /// Whether to continue loop execution
    bool running;
    
    // These methods only need to be called by run()
protected:
    /// Runs every loop, use for physics stuff
    virtual const SUCCESS loop()=0;
    
    /// Redisplays the data or whatever
    virtual const SUCCESS display() const=0;
    
    /// Runs once control is given to this loop
    virtual const SUCCESS load()=0;
    
    /// Runs before control is yielded back to App
    virtual const SUCCESS unload()=0;
    
public:
    virtual ~GameLoop() {};
    GameLoop(): status(0), running(false) {};
    const SUCCESS run();
};

}
#endif /*_GAME_LOOP_H_*/
