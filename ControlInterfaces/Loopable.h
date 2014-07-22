#ifndef _LOOPABLE_H_
#define _LOOPABLE_H_

#include "Declarations.h"

namespace jer
{
    class Loopable
    {
    private:
        LoopEngine<Loopable *> *list;
        
    public:
        unsigned short references;   /// allows engine loops to know whether to delete the Loopable
        
    public:
        Loopable(LoopEngine<Loopable *> * const engine): references(0) {addSelfToEngine(engine);};
        // Use this constructor if the Loopable is stored on the heap and a LoopEngine will be responsible for its memory management
        Loopable(): list(NULL), references(1) {};
        // Use this constructor if the Loopable will be stored on the stack and scope will be responsible for its memory managemet
        virtual ~Loopable() {removeSelfFromEngine();};
        virtual const SUCCESS loop()=0;  /// Override to loop object
        const bool toDie() const {return references <= 1;}; 
        // Engines use this to determine whether to destroy the Loopable upon its own destruction
    public:
        void addSelfToEngine(LoopEngine<Loopable *> * const engine);
        void removeSelfFromEngine();
        
    private:
        void assignEngine(LoopEngine<Loopable *> * const engine);
        void forgetEngine();
        friend class LoopEngine<Loopable *>;
    };

}
#endif