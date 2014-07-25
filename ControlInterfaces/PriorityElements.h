#ifndef _PRIORITY_ELEMENT_H_
#define _PRIORITY_ELEMENT_H_

#include "Declarations.h"

namespace jer
{
    class PriorityInterface
    {
    public:
        virtual ~PriorityInterface() {};
        
    public:
        virtual const int getPriority() const {return 0;}; // not abstract cuz you dont always have to implement it y'know
    };
    
    template<class T>
    class GeneralPriorityElement: public PriorityInterface, public T {};
    
    template<class T>
    class PriorityElement: public T, public PriorityInterface
    {
    private:
        int priority;
        
    public:
        PriorityElement(const T& init, const int initP=0): T(init), priority(initP) {};
        PriorityElement(const int initP=0): priority(initP) {};
        PriorityElement(const PriorityElement &other): T(other), priority(other.priority) {};
        virtual ~PriorityElement() {};
        
    public:
        virtual const int getPriority() const {return priority;};
        virtual void setPriority(const int p) {priority = p;};
    };
    
    const bool comparePriorityElements(const PriorityInterface &a, const PriorityInterface &b)
    {
        return a.getPriority() < b.getPriority();
    }
    
    const bool comparePriorityElementPointers(PriorityInterface *const a, PriorityInterface * const b)
    {
        if(a == NULL)
            return true;
        else if(b == NULL)
            return false;
        else
            return a->getPriority() < b->getPriority();
    }
}

#endif /*_PRIORITY_ELEMENT_H_*/