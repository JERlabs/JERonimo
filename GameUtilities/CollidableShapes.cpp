#include "CollidableShapes.h"

namespace jer
{
    const bool RectangleCollidable::canCollide(const int t) const
    {
        return t == RECTANGLE || t == POINT;
    }
    
    const bool RectangleCollidable::collides(const Collidable &other) const
    {
		Point<double> topLeft(getTopLeft());
		Point<double> bottomRight(getBottomRight());
		
        switch(other.getType())
        {
        case POINT:
            if(other.getPosition().x() < bottomRight.x() && other.getPosition().x() > topLeft.x() &&
				other.getPosition().y() < bottomRight.y() && other.getPosition().y() > topLeft.y())
				return true;
			else
				return false;
		case RECTANGLE:
			{
				Point<double> otherTopLeft(other.getOffset()+other.getPosition());
				Point<double> otherBottomRight(otherTopLeft+other.getDimensions());
				
				if(otherTopLeft.x() < bottomRight.x() && otherBottomRight.x() > topLeft.x() &&
					otherTopLeft.y() < bottomRight.y() && otherBottomRight.y() > topLeft.y())
					return true;
				else
					return false;
			}
			/*
		case CIRCLE:
			{
				To be completed
			}
			*/
		default:
			if(other.canCollide(getType()))
				return other.collides(*this);
			return false;
        }
    }
    
}