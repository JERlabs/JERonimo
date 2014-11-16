#ifndef _LOOPABLE_H_
#define _LOOPABLE_H_

#include <memory>

#include "Declarations.h"

namespace jer
{
    using std::shared_ptr;
    
	/** Abstract class for interface of looped game elements.
	 * These objects should have a routine which is meant to be run once every frame.
	 * One should derive a Loopable and override the loop function, 
	 * then pass that object into a list of Loopable references to be executed every frame
	 * \see Displayable
	 * \see Loadable
	 * \see LoopWrapper
	 * \see LoopEngine
	 */
    class Loopable
    {   
    public:
		/// Default constructor
        Loopable() {};
		
		/// Destructor
        virtual ~Loopable() {};
		
		/** This function should be overridden in a derived class with the routine which runs once per frame.
		 * It's called every frame by LoopEngine's.
		 * \return status code defined by derived class. Negative on failure, non-negative on success
		 */
        virtual const SUCCESS loop()=0;  /// Override to loop object
    };
    
	/** Wrapper class for memory management of Loopable
	 * All Loopable's should be allocated dynamically.
	 */
    class LoopWrapper: public shared_ptr<Loopable>, public Loopable
    {
    public:
		/// shared_ptr<Loopable>'s destructor will handle memory
        virtual ~LoopWrapper() {};
		
        LoopWrapper(Loopable * const comp=nullptr): shared_ptr<Loopable>(comp) {};
		
		/// Constructor from a shared_ptr of a dynamically allocated Loopable object
        LoopWrapper(const shared_ptr<Loopable>& other): shared_ptr<Loopable>(other) {};
		
		/// Copy Constructor
        LoopWrapper(const LoopWrapper& other): shared_ptr<Loopable>(other) {};
        
    public:
		/** Calls the Loopable object being managed's loop function
		 * \return the return value of the managed object's loop(), or jer::FAILED if no object is being managed.
		 * \see Loopable::loop
		 */
        virtual const SUCCESS loop() override {return get()? get()->loop():-1;};
    };

}
#endif