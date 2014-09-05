#include "PhysicalObject.h"

namespace jer
{
    double Mass::GRAVITATIONAL_CONSTANT(10.0);
    
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
    
    const SUCCESS PhysicalObject::collided(const PhysicalObject &object)
    {
		Point<double> mInit((getVelocity()-other.getVelocity())*getMass());
		Vector m1, m2;
		if(object.getCollider()->getType() == Collidable::CIRCLE && getCollider()->getType() == Collidable::CIRCLE)
		{
			m1.theta(Vector(getPosition()-object.getPosition()).theta());
			if(m1.theta() < mInit)
				m2.theta(m1.theta()-Degrees(90.0));
			else
				m2.theta(m1.theta()+Degrees(90.0));
			
		}
		
    }
}