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
    
    const SUCCESS PhysicalObject::collided(PhysicalObject &object, const Radians angle)
    {
        Mag_t<double> initVel(pythagoras<double>((getVelocity().x()-object.getVelocity().x()), (getVelocity().y()-object.getVelocity().y())));  
        // Frame of reference with the object at rest with this approaching it with an angle of 0
        Point<double> p2(Vector(Mag_t<double>(2.0*getMass()*getX(initVel, angle)/(getMass()+object.getMass())), angle));  // Gets the velocity of 2 based on elastic collision equation
        Point<double> p1((initVel*getMass()-p2.x()*object.getMass())/getMass(), -p2.y()*object.getMass()/getMass());   // Gets the velocity of 1 based off of elastic collision rulez
        
        Vector v1(p1);
        Vector v2(p2);
        
        Radians temp;
        v1.theta(v1.theta()+(temp = getTheta(getVelocity())));
        v2.theta(v2.theta()+temp);
        
        v1 += object.getVelocity();
        v2 += object.getVelocity();
        
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
                if(object.getCollider()->collides(*object.getCollider()))
                    return object.collided(*this, Collidable::GetCollisionAngle(getCollider(), object.getCollider()));
                else
                    return SUCCEEDED;
            else
                return FAILED;
        }
    }
}