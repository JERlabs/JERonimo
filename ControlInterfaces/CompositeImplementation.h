#ifndef _COMPOSITE_IMPLEMENTATION_H_
#define _COMPOSITE_IMPLEMENTATION_H_

#include "Declarations.h"
#include "Loadable.h"
#include "Loopable.h"
#include "Displayable.h"
#include "Runnable.h"

namespace jer
{
    /** Implementation for a Process type which is composed of three dynamic objects, a LoadWrapper, LoopWrapper, and DisplayWrapper
     * The class naturally inherits load, loop, and display which allow its interface to be equivalent to SimpleImplementation.
     * The client code should not free the Control Objects it passes in.
     */
    class CompositeImplementation: public LoadWrapper, public LoopWrapper, public DisplayWrapper
    {
    public:
        /// Destructor
        virtual ~CompositeImplementation() {if(this->isLoaded()) this->unload();};
        
        /// Default Constructor
        CompositeImplementation() {};
        
        /** Constructor
         * The three Control Objects passed in should be dynamically allocated but not deleted by client code
         */
        CompositeImplementation(Loadable * const loadPart, 
                          Loopable * const loopPart, 
                          Displayable * const displayPart): 
                          LoadWrapper(loadPart), 
                          LoopWrapper(loopPart), 
                          DisplayWrapper(displayPart) {};
                          
        /// Constructor
        CompositeImplementation(const LoadWrapper &loadPart,
                                const LoopWrapper &loopPart,
                                const DisplayWrapper &displayPart):
                                LoadWrapper(loadPart),
                                LoopWrapper(loopPart),
                                DisplayWrapper(displayPart) {};
                          
    public:
        const LoadWrapper &getLoader() const {return *this;};  ///< Gets LoadWrapper part of object
        const LoopWrapper &getLooper() const {return *this;};  ///< Gets LoopWrapper part of object
        const DisplayWrapper &getDisplayer() const {return *this;};  ///< Gets DisplayWrapper part of object
        void setLoader(const LoadWrapper &loadPart) {this->LoadWrapper::operator=(loadPart);};   ///< reassigns LoadWrapper part of object
        void setLooper(const LoopWrapper &loopPart) {this->LoopWrapper::operator=(loopPart);};   ///< reassigns LoopWrapper part of object
        void setDisplayer(const DisplayWrapper &displayPart) {this->DisplayWrapper::operator=(displayPart);};   ///< reassigns DisplayWrapper pat of object
    };
    
    typedef CompositeImplementation CompImpl;
    
    /// Shorthand for a process that implements Composite Implementation
    using CompositeProcess = Process<CompositeImplementation>;
}

#endif /*_COMPOSITE_RUNNABLE_H_*/