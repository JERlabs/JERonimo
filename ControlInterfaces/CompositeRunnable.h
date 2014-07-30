#ifndef _COMPOSITE_RUNNABLE_H_
#define _COMPOSITE_RUNNABLE_H_

#include "Declarations.h"
#include "Loadable.h"
#include "Loopable.h"
#include "Displayable.h"

namespace jer
{
    class CompositeRunnable: public LoadWrapper, public LoopWrapper, public DisplayWrapper
    {
    protected:
        LoopWrapper *looper;
        LoadWrapper *loader;
        DisplayWrapper *displayer;
        
    protected:
        int status;
        bool running;        
        
    public:
        virtual ~CompositeRunnable() {if(loader->isLoaded()) loader->unload();};
        CompositeRunnable(): looper(this), loader(this), displayer(this) {};
        CompositeRunnable(Loadable * const loadPart, 
                          Loopable * const loopPart, 
                          Displayable * const displayPart): 
                          LoadWrapper(loadPart), 
                          LoopWrapper(loopPart), 
                          DisplayWrapper(displayPart),
                          looper(this), loader(this), displayer(this) {};
                          
    public:
        void setLoader(Loadable * const loadPart) {loader->reset(loadPart);};
        void setLooper(Loopable * const loopPart) {looper->reset(loopPart);};
        void setDisplayer(Displayable * const displayPart) {displayer->reset(displayPart);};
        Loadable * const getLoader() const {return loader->get();};
        Loopable * const getLooper() const {return looper->get();};
        Displayable * const getDisplayer() const {return displayer->get();};
        
    public:
        virtual const SUCCESS run();
    };
}

#endif /*_COMPOSITE_RUNNABLE_H_*/