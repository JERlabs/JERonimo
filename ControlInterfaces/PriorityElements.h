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
    
    class PriorityElement: public virtual PriorityInterface
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
    
    inline const bool comparePriorityElements(const PriorityInterface &a, const PriorityInterface &b)
    {
        return a.getPriority() < b.getPriority();
    }
    
    inline const bool comparePriorityElementPointers(const shared_ptr<PriorityInterface> &a, const shared_ptr<PriorityInterface> &b)
    {
        return a->getPriority() < b->getPriority();
    }
    
    template<class T>
    class PriorityControlInterface: public T, public virtual PriorityInterface 
    {
    public:
        PriorityControlInterface(const T& copy): T(copy) {};
        PriorityControlInterface() {};
    };
    
    template<class T>
    class PriorityControlElement: public PriorityControlInterface<T>, public virtual PriorityElement 
    {
    public:
        PriorityControlElement(const int initP=0): PriorityElement(initP) {};
        PriorityControlElement(const PriorityElement& other): PriorityElement(other) {};
        PriorityControlElement(const T& copy, const int initP=0): PriorityControlInterface<T>(copy), PriorityElement(initP) {};
        PriorityControlElement(const PriorityControlElement<T> &other): PriorityControlInterface<T>(other), PriorityElement(other) {};
    };
    
    using PriorityLoadable      = PriorityControlInterface<Loadable>;
    using PriorityLoopable      = PriorityControlInterface<Loopable>;
    using PriorityDisplayable   = PriorityControlInterface<Displayable>;
}

#endif /*_PRIORITY_ELEMENT_H_*/