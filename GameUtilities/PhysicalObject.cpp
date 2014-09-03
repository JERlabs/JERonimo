#include "PhysicalObject.h"

namespace jer
{
    double Mass::GRAVITATIONAL_CONSTANT(1.0);
    
    const Scalar<double> Mass::GetGravityForce(const Mass &first, const Mass &second, const Scalar<double> &distance)
    {
        return (GRAVITATIONAL_CONSTANT*first*second)/(distance*distance);
    }
    
    void PhysicalObject::gravitate(const PhysicalObject &other)
    {
        Vector distance(getPosition()-other.getPosition());
        force(Vector(Mag_t<double>(-Mass::GetGravityForce(getMass(), other.getMass(), distance.mag())/getMass()), distance.theta()));
    }
    
    const SUCCESS PhysicalObject::loop()
    {
        const SUCCESS ret = acceleration.loop();
        acceleration = Point<double>(0.0, 0.0);
        return ret;
    }
}