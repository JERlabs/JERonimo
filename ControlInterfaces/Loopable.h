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
        Loopable(LoopEngine<Loopable *> * const engine=NULL): references(engine==NULL? 1:0) {addSelfToEngine(engine);};
        virtual ~Loopable() {removeSelfFromEngine();};
        virtual const SUCCESS loop()=0;  /// Override to loop object
        const bool toDie() const {return references == 1;}; // Engines use this to determine whether to destroy the Loopable upon its own destruction
        
    public:
        void addSelfToEngine(LoopEngine<Loopable *> * const engine);
        void removeSelfFromEngine();
        
    private:
        void forgetEngine();
        friend class LoopEngine<Loopable *>;
    };

}
#endif