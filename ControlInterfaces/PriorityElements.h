#ifndef _PRIORITY_ELEMENT_H_
#define _PRIORITY_ELEMENT_H_

#include <memory>
#include "Declarations.h"

namespace jer
{
    using std::shared_ptr;
    class PriorityInterface
    {
    public:
        virtual ~PriorityInterface() {};
        
    public:
        virtual const int getPriority() const {return 0;}; // not abstract cuz you dont always have to implement it y'know
    };
    
    class PriorityElement: public PriorityInterface
    {
    private:
        int priority;
        
    public:
        PriorityElement(const int initP=0): priority(initP) {};
        PriorityElement(const PriorityElement &other): priority(other.priority) {};
        virtual ~PriorityElement() {};
        
    public:
        virtual const int getPriority() const {return priority;};
        virtual void setPriority(const int p) {priority = p;};
    };
    
    const bool comparePriorityElements(const PriorityInterface &a, const PriorityInterface &b)
    {
        return a.getPriority() < b.getPriority();
    }
    
    const bool comparePriorityElementPointers(const shared_ptr<PriorityInterface> &a, const shared_ptr<PriorityInterface> &b)
    {
        return a->getPriority() < b->getPriority();
    }
    
    template<class T>
    class PriorityControlInterface: public T, public PriorityInterface {};
    
    using PriorityLoadable      = PriorityControlInterface<Loadable>;
    using PriorityLoopable      = PriorityControlInterface<Loopable>;
    using PriorityDisplayable   = PriorityControlInterface<Displayable>;
}

#endif /*_PRIORITY_ELEMENT_H_*/