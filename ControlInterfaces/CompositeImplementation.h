#ifndef _COMPOSITE_IMPLEMENTATION_H_
#define _COMPOSITE_IMPLEMENTATION_H_

#include "Declarations.h"
#include "Loadable.h"
#include "Loopable.h"
#include "Displayable.h"
#include "Runnable.h"

namespace jer
{
    class CompositeImplementation: public LoadWrapper, public LoopWrapper, public DisplayWrapper
    {
    /*
    protected:
        LoopWrapper *looper;
        LoadWrapper *loader;
        DisplayWrapper *displayer;
    */    
    public:
        virtual ~CompositeImplementation() {if(this->isLoaded()) this->unload();};
        CompositeImplementation()/*: looper(this), loader(this), displayer(this)*/ {};
        CompositeImplementation(Loadable * const loadPart, 
                          Loopable * const loopPart, 
                          Displayable * const displayPart): 
                          LoadWrapper(loadPart), 
                          LoopWrapper(loopPart), 
                          DisplayWrapper(displayPart)/*,
                          looper(this), loader(this), displayer(this)*/ {};
                          
    public:
        /*
        void setLoader(Loadable * const loadPart) {LoadWrapper::reset(loadPart);};
        void setLooper(Loopable * const loopPart) {LoopWrapper::reset(loopPart);};
        void setDisplayer(Displayable * const displayPart) {DisplayWrapper::reset(displayPart);};
        Loadable * const getLoader() const {return LoadWrapper::get();};
        Loopable * const getLooper() const {return LoopWrapper::get();};
        Displayable * const getDisplayer() const {return DisplayWrapper::get();};
        */
        const LoadWrapper &getLoader() const {return *this;};
        const LoopWrapper &getLooper() const {return *this;};
        const DisplayWrapper &getDisplayer() const {return *this;};
        void setLoader(const LoadWrapper &loadPart) {this->LoadWrapper::operator=(loadPart);};
        void setLooper(const LoopWrapper &loopPart) {this->LoopWrapper::operator=(loopPart);};
        void setDisplayer(const DisplayWrapper &displayPart) {this->DisplayWrapper::operator=(displayPart);};
    };
    
    typedef CompositeImplementation CompImpl;
    using CompositeProcess = Process<CompositeImplementation>;
}

#endif /*_COMPOSITE_RUNNABLE_H_*/