#include "CollidableShapes.h"

namespace jer
{
    RectangleCollidable::~RectangleCollidable()
    {
        if(point && erasePoint)
            delete point;
        if(dim && eraseDim)
            delete dim;
    }
    
    void RectangleCollidable::setVertex(const Point<double> * const vertRef)
    {
        if(point && erasePoint)
            delete point;
        point = vertRef;
        erasePoint = false;
    }
    
    void RectangleCollidable::setDimensions(const Dimensions<double> * const dimRef)
    {
        if(dim && eraseDim)
            delete dim;
        dim = dimRef;
        eraseDim = false;
    }
    
    const bool RectangleCollidable::canCollide(const int t) const
    {
        return t == RECTANGLE || t == POINT;
    }
    
    const bool RectangleCollidable::collides(const Collidable &other) const
    {
        switch(other.getType())
        {
        case POINT:
            
        }
    }
    
}