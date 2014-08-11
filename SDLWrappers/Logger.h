#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>

#include "Declarations.h"
#include "ControlInterfaces/Runnable.h"

namespace jer
{    
    using std::string;
    const SUCCESS log(const SUCCESS error, const string& caller);
    inline const SUCCESS log(const SUCCESS error) {return log(error, "unknown");};
    
    template<class PROCESS_IMPLEMENTATION>
    class Logger: public PROCESS_IMPLEMENTATION
    {
    private:
        static string name;
    public:
        virtual ~Logger() {};
        Logger() {};
        Logger(Loadable * const loadPart, Loopable * const loopPart, Displayable * const displayPart):
            PROCESS_IMPLEMENTATION(loadPart, loopPart, displayPart) {};
            
    public:
        virtual const SUCCESS load() {return log(PROCESS_IMPLEMENTATION::load(), name+"::load()");};
        virtual const SUCCESS unload() {return log(PROCESS_IMPLEMENTATION::unload(), name+"::unload()");};
        virtual const SUCCESS loop() {return log(PROCESS_IMPLEMENTATION::loop(), name+"::loop()");};
        virtual const SUCCESS display() const {return log(PROCESS_IMPLEMENTATION::display(), name+"::display()");};
    };
    
    template<class PROCESS_IMPLEMENTATION> string Logger<PROCESS_IMPLEMENTATION>::name(typeid(PROCESS_IMPLEMENTATION).name());
}


#endif /*_LOGGER_H_*/