#ifndef _DISPLAYABLE_H_
#define _DISPLAYABLE_H_

#include <memory>

#include "Declarations.h"
namespace jer
{
    using std::shared_ptr;
	
	/** Abstract class for interface of displayed game elements.
	 * These objects should have a routine which is meant to be run every frame, without conceptually changing internal data.
	 * One should derive a Displayable and override the display function,
	 * then pass that object into a list of Displayable references to be once every frame
	 * \see Loopable
	 * \see Loadable
	 * \see DisplayWrapper
	 * \see DisplayQueue
	 */
    class Displayable
    {        
    public:
		/// Destructor
        virtual ~Displayable() {};
		
		/// Default Constructor
        Displayable() {};
        
    public:
		/** This function should be overridden in a derived class with the routine which runs once per frame.
		 * It's called every frame by DisplayQueue's.
		 * Function is constant, and shouldn't change any conceptual internal data.
		 * \return status code defined by derived class. Negative on failure, non-negative on success
		 */
        virtual const SUCCESS display() const=0;   // We'll see about this const rule.
    };
    
	/** Wrapper class for memory management of Displayable
	 * All Displayable's should be allocated dynamically.
	 */
    class DisplayWrapper: public shared_ptr<Displayable>, public Displayable
    {
    public:
		/// Destructor, shared_ptr ensures proper clean up of Displayable
        virtual ~DisplayWrapper() {};
		
		/// (Default) Construct from pointer to dynamically allocated Displayable object.
        DisplayWrapper(Displayable * const comp=nullptr): shared_ptr<Displayable>(comp) {};
		
		/// Construct from shared_ptr of dynamically allocated Displayable object.
        DisplayWrapper(const shared_ptr<Displayable>& other): shared_ptr<Displayable>(other) {};
		
		/// Copy Constructor
        DisplayWrapper(const DisplayWrapper& other): shared_ptr<Displayable>(other) {};
        
    public:
		/** Calls the Loadable object being managed's display function
		 * \return the return value of the managed object's display, or jer::FAILED if no object is being managed.
		 * \see Displayable::display
		 */
        virtual const SUCCESS display() const override {return get()? get()->display():-1;};
    };

}

#endif
