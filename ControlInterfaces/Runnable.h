#ifndef _RUNNABLE_H_
#define _RUNNABLE_H_

#include "Declarations.h"
#include "Loopable.h"
#include "Displayable.h"
#include "Loadable.h"

namespace jer {
// Events is only needed by run to call handleEvent
class Runnable//: public Loadable, public Loopable, public Displayable
{
protected:
    /// Return Status of the Runnable's run function
    int status;
    
    /// Whether to continue loop execution
    bool running;
    
public:
    virtual ~Runnable() {};
    Runnable(): status(0), running(false) {};
    
public:
    virtual const SUCCESS run()=0;
	const int getStatus() const {return status;};
	const bool isRunning() const {return running;};
	void stop() {running = false;};
};

class SimpleRunnable: public Runnable, public Loadable, public Loopable, public  Displayable 
{
public:
	virtual const SUCCESS run();
};

}
#endif /*_RUNNABLE_H_*/