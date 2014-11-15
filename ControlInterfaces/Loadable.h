#ifndef _LOADABLE_H_
#define _LOADABLE_H_

#include <memory>

#include "Declarations.h"

namespace jer
{
    using std::shared_ptr;
    
    /** Abstract class for interface of loaded game elements.
	 * These objects should have a routine which is meant to be run before the resources use, and after, safely loading the resource into memory, and cleaning the resource from memory.
	 * One should derive a Loadable and override the load and unload functions,
	 * then pass that object into a list of Loadable references to be executed before and after the resources are used
	 * \see Displayable
	 * \see Loopable
	 * \see LoadWrapper
	 * \see DataManager
	 */
    class Loadable
    {
    private:
        bool loaded;  ///< True if the memory is currently loaded into memory. False otherwise.
        
    public:
		/// Default constructor
        Loadable(): loaded(false) {};
		
		/// Copy constructor
        Loadable(const Loadable& other): loaded(other.loaded) {};
		
		/// Destructor
        virtual ~Loadable() {};
		
		/** This function should be overriden in a derived class with a routine which loads in a resource from memory.
		 * The default implementation provided sets loaded to true and returns jer::SUCCEEDED.
		 * \return status code defined by derived class. Negative on failure code should also guarantee that loaded is false. Non-negative on success should also imply that loaded is true.
		 * \see Loadable::unload
		 */
        virtual const SUCCESS load()=0;
		
		/** This function should be overriden in a derived class with a routine which ensures the resources is cleared from memory and freed.
		 * The default implementation provided sets loaded to false and returns jer::SUCCEEDED.
		 * \return status code defined by derived class. Negative on failure code, Non-negative on success. Regardless it's assumed that the resource can no longer be utilized and loaded should be false.
		 * \see Loadable::load
		 */
        virtual const SUCCESS unload()=0;
		
		/// Returns true if resource is loaded and ready to be utilized, false otherwise
        const bool isLoaded() const {return loaded;};  /// Used to check the state of the loadable object
    };
    
    inline const SUCCESS Loadable::load()
    {
        loaded = true;
        return SUCCEEDED;
    }
    
    inline const SUCCESS Loadable::unload()
    {
        loaded = false;
        return SUCCEEDED;
    }
    
	/** Wrapper class for memory management of Loadable
	 * All Loadable's should be allocated dynamically.
	 *//** Wrapper class for memory management of Loadable
	 * All Loadable's should be allocated dynamically.
	 */
    class LoadWrapper: public shared_ptr<Loadable>, public Loadable
    {
    public:
		/// Destructor. Unloads resource before the Loadable is deleted.
        virtual ~LoadWrapper() {if(get()->isLoaded()) get()->unload();};
		
		/// (Default) Construct from pointer to dynamically allocated Loadable object
        LoadWrapper(Loadable * const comp=nullptr): shared_ptr<Loadable>(comp) {};
		
		/// Construct from shared_ptr managing dynamically allocated Loadable object
        LoadWrapper(const shared_ptr<Loadable>& other): shared_ptr<Loadable>(other) {};
		
		/// Copy Constructor
        LoadWrapper(const LoadWrapper& other): shared_ptr<Loadable>(other), Loadable(other) {};
        
    public:
		/** Calls the Loadable object being managed's load function
		 * \return the return value of the managed object's load, or jer::FAILED if no object is being managed.
		 * \see LoadWrapper::unload
		 * \see Loadable::load
		 */
        virtual const SUCCESS load() override 
        {
            if(get())
            {
				const ret = get()->load();
				if(ret >= SUCCEEDED)
					Loadable::load();
                return ret;
            }
            return FAILED;
        };
		
		/** Calls the Loadable object being managed's unload function
		 * \return the return value of the managed object's unload, or jer::FAILED if no object is being managed.
		 * \see LoadWrapper::load
		 * \see Loadable::unload
		 */
        virtual const SUCCESS unload() override 
        {
            Loadable::unload();
            if(get())
            {
                return get()->unload();
            }
            return FAILED;            
        };
    };

}
#endif
