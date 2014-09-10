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
            return other.getPosition().x() < bottomRight.x() && other.getPosition().x() > topLeft.x() &&
				other.getPosition().y() < bottomRight.y() && other.getPosition().y() > topLeft.y();
		case RECTANGLE:
			{
				Point<double> otherTopLeft(other.getOffset()+other.getPosition());
				Point<double> otherBottomRight(otherTopLeft+other.getDimensions());
				
				return otherTopLeft.x() < bottomRight.x() && otherBottomRight.x() > topLeft.x() &&
					otherTopLeft.y() < bottomRight.y() && otherBottomRight.y() > topLeft.y();
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
	
	const bool CircleCollidable::canCollide(const int t) const
	{
		return t == RECTANGLE || t == POINT || t == CIRCLE;
	}
	
	const bool CircleCollidable::collides(const Collidable& other) const
	{
		switch(other.getType())
		{
		case POINT:
			return pythagoras(getCenter()-other.getPosition()) < radius;
			
		case RECTANGLE:
			{
				Point<double> temp(other.getOffset() + other.getPosition());
				Point<double> corners[4] = {other.getOffset()+other.getPosition(), temp+other.getDimensions(), temp+other.getDimensions().x(), temp+other.getDimensions().y()};
				Point<double> cardinals[4] = {getCenter() + X_t<double>(radius), getCenter() - X_t<double>(radius), getCenter() + Y_t<double>(radius), getCenter() - Y_t<double>(radius)};
				
				for(int i = 0; i < 4; i++)
				{
					if(collides(Collidable(POINT, corners+i)))
						return true;
					else if(other.collides(Collidable(POINT, cardinals+i)))
						return true;
				}
				
				return false;
			}
		
		case CIRCLE:
			return pythagoras(getCenter() - (other.getPosition() + other.getOffset())) < other.getDimensions().x()+radius;
			
		default:
			if(other.canCollide(getType()))
				return other.collides(*this);
			return false;
		}
	}
    
}