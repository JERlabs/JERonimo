#ifndef _RUNNABLE_H_
#define _RUNNABLE_H_

#include "Declarations.h"
#include "Loopable.h"
#include "Displayable.h"
#include "Loadable.h"

namespace jer {

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

class SimpleImplementation: public Loadable, public Loopable, public Displayable {};

template<class IMPLEMENTATION>   /// Should be a type supporting Loadable, Loopable, and Displayable
class Process: public Runnable, public IMPLEMENTATION
{
public:
    virtual ~Process() {};
    Process() {};
    Process(Loadable * const loadPart, Loopable * const loopPart, Displayable * const displayPart): 
        IMPLEMENTATION(loadPart, loopPart, displayPart) {};
    
public:
	virtual const SUCCESS run()
    {
        if((status = this->load()) < SUCCEEDED)
            return status;
        
        running = true;
        while (running) {
            if((status = this->loop()) < SUCCEEDED)
                break;
            if((status = this->display()) < SUCCEEDED)
                break;
        }
        
        status = this->unload();
        return status;
    };
    
};

using SimpleProcess = Process<SimpleImplementation>;

}
#endif /*_RUNNABLE_H_*/