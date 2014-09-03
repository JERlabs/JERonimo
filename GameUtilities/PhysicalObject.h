#ifndef _PHYSICAL_OBJECT_H_
#define _PHYSICAL_OBJECT_H_

#include "ControlInterfaces/Loopable.h"
#include "Space2D/Point.h"
#include "Space2D/Vector.h"
#include "Space2D/Delta.h"

namespace jer
{
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
        
    public:
        ~PhysicalObject() {};
        PhysicalObject(const Mass &m, const Point<double>& initPos, const Point<double>& initVel, const Point<double>& initAcc):
                        mass(m), acceleration(initAcc, Delta<Point<double> >(initVel, initPos)), velocity(&acceleration.get(2)), position(&acceleration.get(1)) {};
        PhysicalObject(const Mass &m, const Point<double>& initPos, const Point<double>& initVel): PhysicalObject(m, initPos, initVel, Point<double>()) {};
        PhysicalObject(const Mass &m, const Point<double>& initPos): PhysicalObject(m, initPos, Point<double>()) {};
        PhysicalObject(const Mass &m): PhysicalObject(m, Point<double>()) {};
        PhysicalObject(): PhysicalObject(0.0) {};
        PhysicalObject(const Mass &m, const Delta<Delta<Point<double> > > &init): PhysicalObject(m, init.get(1), init.get(2), init) {};
        PhysicalObject(const PhysicalObject &other): PhysicalObject(other.mass, other.acceleration) {};
        
    public:
        const Mass &getMass() const {return mass;};
        void setMass(const Mass &m) {mass = m;};
        
        const Point<double> &getAcceleration() const {return acceleration;};
        void setAcceleration(const Point<double> &accel) {acceleration = accel;};
        
        const Point<double> &getVelocity() const {return *velocity;};
        void setVelocity(const Point<double> &vel) {acceleration.set(Delta<Point<double> >(vel, *position));};
        
        const Point<double> &getPosition() const {return *position;};
        void setPosition(const Point<double> &pos) {acceleration.set(pos);};
        
    public:
        void force(const Point<double> &f) {acceleration += f;};
        void gravitate(const PhysicalObject &other);
        
    public:
        virtual const SUCCESS loop() override;
    };
}


#endif /*_PHYSICAL_OBJECT_H_*/