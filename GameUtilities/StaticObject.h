#ifndef _STATIC_OBJECT_H_
#define _STATIC_OBJECT_H_

#include "PhysicalObject.h"

namespace jer
{
    class StaticObject: public PhysicalObject
    {
    public:
        virtual ~StaticObject() {};
        StaticObject(const Mass &m, const Point<double>& initPos, Collidable * const col=NULL, const FPSManager * const fps=NULL): PhysicalObject(m, initPos, col, fps) {};
        StaticObject(const Mass &m, Collidable * const col=NULL, const FPSManager * const fps=NULL): PhysicalObject(m, col, fps) {};
        StaticObject(Collidable * const col=NULL, const FPSManager * const fps=NULL): PhysicalObject(col, fps) {};
        StaticObject(const StaticObject& other): PhysicalObject(other) {};
        
    public:
        virtual StaticObject * const clone() const {return new StaticObject(*this);};
        
    public:
        virtual const SUCCESS loop() override;
        virtual const SUCCESS checkCollision(PhysicalObject &object);
        virtual const SUCCESS collided(PhysicalObject &object, const Radians angle) override;
    };
}

#endif /*_STATIC_OBJECT_H_*/