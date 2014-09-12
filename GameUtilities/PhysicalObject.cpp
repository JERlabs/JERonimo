#include "PhysicalObject.h"

namespace jer
{
    double Mass::GRAVITATIONAL_CONSTANT(0.1);
    double PhysicalObject::REST_THRESHOLD(0.1);
    
    const Scalar<double> Mass::GetGravityForce(const Mass &first, const Mass &second, const Scalar<double> &distance)
    {
        return (GRAVITATIONAL_CONSTANT*first*second)/(distance*distance);
    }
    
    void PhysicalObject::gravitate(const PhysicalObject &other)
    {
        Vector distance(getPosition()-other.getPosition());
        force(Vector(Mag_t<double>(-Mass::GetGravityForce(getMass(), other.getMass(), distance.mag())/getMass()), distance.theta()));
    }
    
    void PhysicalObject::antigravitate(const PhysicalObject &other)
    {
        Vector distance(getPosition()-other.getPosition());
        force(Vector(Mag_t<double>(Mass::GetGravityForce(getMass(), other.getMass(), distance.mag())/getMass()), distance.theta()));
    }
    
    const SUCCESS PhysicalObject::loop()
    {
        const SUCCESS ret = acceleration.loop();
        acceleration = Point<double>(0.0, 0.0);
        return ret;
    }
    
    const SUCCESS PhysicalObject::collided(PhysicalObject &object, const Radians angle)
    {
        Vector initVec(getVelocity()-object.getVelocity());
        Mag_t<double> initVel(initVec.mag());
        Radians initTheta(initVec.theta());
        
		if(fabs(getX(initVel, initTheta-angle)) < REST_THRESHOLD)
        {
			setVelocity(getVelocity()+initVec/2.0);
			object.setVelocity(object.getVelocity()-initVec/2.0);
            antigravitate(object);
            object.antigravitate(*this);
			return SUCCEEDED;
		}
		
        // Frame of reference with the object at rest with this approaching it with an angle of 0
        Point<double> p2(Vector(Mag_t<double>(2.0*getMass()*getX(initVel, initTheta-angle)/(getMass()+object.getMass())), initTheta-angle));  // Gets the velocity of 2 based on elastic collision equation
        Point<double> p1((initVel*getMass()-p2.x()*object.getMass())/getMass(), -p2.y()*object.getMass()/getMass());   // Gets the velocity of 1 based off of elastic collision rulez
        
        if(abs(p1.x()) < REST_THRESHOLD && abs(p2.x()) < REST_THRESHOLD)
        {
            p1.x(0.0);
            p2.x(0.0);
        }
        
        Vector v1(p1);
        Vector v2(p2);
        
        v1.theta(-v1.theta()+initTheta);
        v2.theta(angle);
        
        v1 += object.getVelocity();
        v2 += object.getVelocity();
        
        Point<double> dif(object.getPosition()-*position);
        while(getCollider()->collides(*object.getCollider()))
            acceleration.set(*position-dif/pythagoras<double>(dif));
        
        setVelocity(v1);
        object.setVelocity(v2);
        
        return SUCCEEDED;
    }
    
    const SUCCESS PhysicalObject::checkCollision(PhysicalObject &object)
    {
        if(getCollider() == NULL || object.getCollider() == NULL)
        {
            return SUCCEEDED;
        }
        else
        {
            if(collider->canCollide(object.getCollider()->getType()))
                if(collider->collides(*object.getCollider()))
                    return collided(object, Collidable::GetCollisionAngle(getCollider(), object.getCollider()));
                else
                    return SUCCEEDED;
            else if(object.getCollider()->canCollide(collider->getType()))
                if(object.getCollider()->collides(*getCollider()))
                    return object.collided(*this, Collidable::GetCollisionAngle(object.getCollider(), getCollider()));
                else
                    return SUCCEEDED;
            else
                return FAILED;
        }
    }
}