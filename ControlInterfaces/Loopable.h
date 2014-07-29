#ifndef _LOOPABLE_H_
#define _LOOPABLE_H_

#include <memory>

#include "Declarations.h"

namespace jer
{
    using std::shared_ptr;
    
    class Loopable
    {   
    public:
        Loopable() {};
        virtual ~Loopable() {};
        virtual const SUCCESS loop()=0;  /// Override to loop object
    };
    
    class LoopWrapper: public shared_ptr<Loopable>, public Loopable
    {
    public:
        virtual ~LoopWrapper() {};
        LoopWrapper(Loopable * const comp=nullptr): shared_ptr<Loopable>(comp) {};
        LoopWrapper(const shared_ptr<Loopable>& other): shared_ptr<Loopable>(other) {};
        
    public:
        const SUCCESS loop() override {return get()? get()->loop():-1;};
    };

}
#endif