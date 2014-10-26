#include "StaticObject.h"

namespace jer
{
    const SUCCESS StaticObject::loop()
    {
        setAcceleration(Point<double>(0.0, 0.0));
        return PhysicalObject::loop();
    }
    
    const SUCCESS StaticObject::collided(PhysicalObject &object, const Radians angle)
    {
        Vector v(object.getVelocity());
        v.theta() -= angle;
        Point<double> appliedMomentum(v);
        if(fabs(appliedMomentum.x()) < REST_THRESHOLD)
        {
            appliedMomentum.x(0);
        }
        appliedMomentum.x() *= -1;
        v = appliedMomentum;
        v.theta() += angle;
        object.setVelocity(v);
        
        Point<double> dif(getPosition()-object.getPosition());
        while(getCollider()->collides(*object.getCollider()))
            object.setPosition(object.getPosition()-dif/pythagoras<double>(dif));
        
        return SUCCEEDED;
    }
    
    const SUCCESS StaticObject::checkCollision(PhysicalObject &object)
    {
        if(getCollider() == NULL || object.getCollider() == NULL)
        {
            return SUCCEEDED;
        }
        else
        {
            Radians angle;
            if(getCollider()->canCollide(object.getCollider()->getType()))
                if(getCollider()->collides(*object.getCollider(), &angle))
                    return collided(object, angle);   // this ensures that object collider is called by this collided function, likewise a derived class needs to make sure its own derived collided function is called
                else
                     return SUCCEEDED;
            else if(object.getCollider()->canCollide(getCollider()->getType()))
                if(object.getCollider()->collides(*getCollider(), &angle))
                     return collided(object, angle);
                else
                     return SUCCEEDED;
            else
                 return FAILED;
        }
    }
}