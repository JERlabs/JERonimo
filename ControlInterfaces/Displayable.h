#ifndef _DISPLAYABLE_H_
#define _DISPLAYABLE_H_

#include <memory>

#include "Declarations.h"
namespace jer
{
    using std::shared_ptr;
    class Displayable
    {        
    public:
        virtual ~Displayable() {};
        Displayable() {};
        
    public:
        virtual const SUCCESS display() const=0;   // We'll see about this const rule.
    };
    
    class DisplayWrapper: public shared_ptr<Displayable>, public Displayable
    {
    public:
        virtual ~DisplayWrapper() {};
        DisplayWrapper(Displayable * const comp=nullptr): shared_ptr<Displayable>(comp) {};
        DisplayWrapper(const shared_ptr<Displayable>& other): shared_ptr<Displayable>(other) {};
        
    public:
        const SUCCESS display() const override {return get()? get()->display():-1;};
    };

}

#endif
