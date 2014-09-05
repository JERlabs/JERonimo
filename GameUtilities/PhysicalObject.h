#ifndef _PHYSICAL_OBJECT_H_
#define _PHYSICAL_OBJECT_H_

#include <memory>

#include "ControlInterfaces/Loopable.h"
#include "Space2D/Point.h"
#include "Space2D/Vector.h"
#include "Space2D/Delta.h"
#include "Collidable.h"

namespace jer
{
    using std::unique_ptr;
    
    class Mass: public Scalar<double>
    {
    private:
        static double GRAVITATIONAL_CONSTANT;
        
    public:
        static void SetGravity(const double g) {GRAVITATIONAL_CONSTANT = g;};
        static double GetGravity() {return GRAVITATIONAL_CONSTANT;};
        static const Scalar<double> GetGravityForce(const Mass &first, const Mass &second, const Scalar<double> &distance);
        
    public:
        Mass(const double &m=0.0): Scalar<double>(m) {};
        Mass(const Mass &m): Scalar<double>(m) {};
    };
    
    
    class PhysicalObject: public Loopable
    {
    private:
        Mass mass;
        
        Delta<Delta<Point<double> > > acceleration;
        const Point<double> *velocity;
        const Point<double> *position;
        
        unique_ptr<Collidable> collider;
        
    public:
        ~PhysicalObject() {};
        PhysicalObject(const Mass &m, const Point<double>& initPos, const Point<double>& initVel, const Point<double>& initAcc, Collidable * const col=NULL):
                        mass(m), acceleration(initAcc, Delta<Point<double> >(initVel, initPos)), velocity(&acceleration.get(2)), position(&acceleration.get(1)), collider(col) {if(bool(collider)) collider->setVertex(getPosition());};
        PhysicalObject(const Mass &m, const Point<double>& initPos, const Point<double>& initVel, Collidable * const col=NULL): PhysicalObject(m, initPos, initVel, Point<double>(), col) {};
        PhysicalObject(const Mass &m, const Point<double>& initPos, Collidable * const col=NULL): PhysicalObject(m, initPos, Point<double>(), col) {};
        PhysicalObject(const Mass &m, Collidable * const col): PhysicalObject(m, Point<double>(), col) {};
        PhysicalObject(Collidable * const col=NULL): PhysicalObject(0.0, col) {};
        PhysicalObject(const Mass &m, const Delta<Delta<Point<double> > > &init, Collidable * const col=NULL): PhysicalObject(m, init.get(1), init.get(2), init, col) {};
        PhysicalObject(const PhysicalObject &other): PhysicalObject(other.mass, other.acceleration, bool(other.collider)? other.collider->copy():NULL) {};
        
    public:
        const Mass &getMass() const {return mass;};
        void setMass(const Mass &m) {mass = m;};
        
        const Point<double> &getAcceleration() const {return acceleration;};
        void setAcceleration(const Point<double> &accel) {acceleration = accel;};
        
        const Point<double> &getVelocity() const {return *velocity;};
        void setVelocity(const Point<double> &vel) {acceleration.set(Delta<Point<double> >(vel, *position));};
        
        const Point<double> &getPosition() const {return *position;};
        void setPosition(const Point<double> &pos) {acceleration.set(pos);};
        
        const Collidable * const getCollider() const {return collider.get();};
        void setCollider(Collidable * const col) {collider.reset(col);};
        
    public:
        void force(const Point<double> &f) {acceleration += f;};
        void gravitate(const PhysicalObject &other);
        const SUCCESS checkCollision(const PhysicalObject &object);
        
    public:
        virtual const SUCCESS loop() override;
        virtual const SUCCESS collided(const PhysicalObject &object);   /// Handles collision physics but can be overriden
    };
}


#endif /*_PHYSICAL_OBJECT_H_*/