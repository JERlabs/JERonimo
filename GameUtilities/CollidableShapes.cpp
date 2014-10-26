#include "CollidableShapes.h"

namespace jer
{
    const bool RectangleCollidable::canCollide(const int t) const
    {
        return t == RECTANGLE || t == POINT;
    }
    
    const bool RectangleCollidable::collidesPoint(const Point<double> p) const
    {
        return p.x() < getBottomRight().x() && p.x() > getTopLeft().x() && p.y() > getBottomRight().y() && p.y() < getTopLeft().y();
    }
    
    const bool RectangleCollidable::collides(const Collidable &other, Radians * const angle) const
    {
		Point<double> bottomLeft(getBottomLeft());
		Point<double> topRight(getTopRight());
		
        switch(other.getType())
        {
        case POINT:
          {
            bool ret = collidesPoint(other.getPosition());
            if(ret && angle)  // if an address was passed in and it does collide
            {
                Point<double> center = getPosition()+getOffset()+getDimensions()/2.0;
                *angle = getTheta(other.getPosition()-center);
                angle->validate();
                Radians refAngle = getTheta(topRight-center)-Radians::ANGLE_RIGHT;
                if(*angle <= refAngle && *angle >= -refAngle)
                    *angle = Radians::ANGLE_RIGHT;
                else if(*angle <= -Radians::ANGLE_LEFT-refAngle && *angle >= refAngle)
                    *angle = Radians::ANGLE_UP;
                else if((*angle <= -Radians::ANGLE_LEFT && *angle >= -Radians::ANGLE_LEFT-refAngle) || (*angle >= Radians::ANGLE_LEFT && *angle <= Radians::ANGLE_LEFT+refAngle))
                    *angle = Radians::ANGLE_LEFT;
                else if(*angle <= -refAngle && *angle >= Radians::ANGLE_LEFT+refAngle)
                    *angle = Radians::ANGLE_DOWN;
            }
            return ret;
          }
		case RECTANGLE:
			{
				Point<double> otherBottomLeft(other.getOffset()+other.getPosition());
				Point<double> otherTopRight(otherBottomLeft+other.getDimensions());
                
				const bool ret = otherBottomLeft.x() < topRight.x() && otherTopRight.x() > bottomLeft.x() &&
					otherBottomLeft.y() < topRight.y() && otherTopRight.y() > bottomLeft.y();
                
                if(ret == false || angle == NULL) return ret;
                
                Uint8 collisions = 0;
                if(collidesPoint(otherBottomLeft)) collisions |= 1;
                if(collidesPoint(otherBottomLeft+other.getDimensions().x())) collisions |= 2;
                if(collidesPoint(otherBottomLeft+other.getDimensions().y())) collisions |= 4;
                if(collidesPoint(otherTopRight)) collisions |= 8;
                
                if(other.collidesPoint(getTopLeft())) collisions |= 16;
                if(other.collidesPoint(getTopRight())) collisions |= 32;
                if(other.collidesPoint(getBottomLeft())) collisions |= 64;
                if(other.collidesPoint(getBottomRight())) collisions |= 128;
                
                switch(collisions)
                {
                case 0:
                    return false;                        
                case 5:
				case 160:
					*angle = Radians::ANGLE_RIGHT;
					break;
				case 10:
				case 80:
					*angle = Radians::ANGLE_LEFT;
					break;
				case 20:
					{
						Point<double> center(getPosition()+getOffset()+getDimensions()/2.0);
						Radians threshold(getTheta(getTopRight()-center));
						Radians actual(getTheta(otherTopRight-center-other.getDimensions().x()));
						if(actual < threshold)
							*angle = Radians::ANGLE_RIGHT;
						else
							*angle = Radians::ANGLE_UP;
						break;
					}
				case 129:
					{
                        Point<double> center(getPosition()+getOffset()+getDimensions()/2.0);
						Radians threshold(getTheta(getBottomRight()-center));
						Radians actual(getTheta(otherBottomLeft-center));
						if(actual < threshold)
							*angle = Radians::ANGLE_DOWN;
						else
							*angle = Radians::ANGLE_RIGHT;
						break;
					}
				case 66:
					{
                        Point<double> center(getPosition()+getOffset()+getDimensions()/2.0);
						Radians threshold(getTheta(getBottomLeft()-center));
						Radians actual(getTheta(otherBottomLeft+other.getDimensions().x()-center));
						if(actual < threshold)
							*angle = Radians::ANGLE_LEFT;
						else
							*angle = Radians::ANGLE_DOWN;
						break;
					}
				case 24:
					{
                        Point<double> center(getPosition()+getOffset()+getDimensions()/2.0);
						Radians threshold(getTheta(getTopLeft()-center));
						Radians actual(getTheta(otherTopRight-center));
						if(actual < threshold)
							*angle = Radians::ANGLE_UP;
						else
							*angle = Radians::ANGLE_LEFT;
						break;
					}
				case 3:
				case 192:
					*angle = Radians::ANGLE_DOWN;
					break;
				case 12:
				case 48:
					*angle = Radians::ANGLE_UP;
					 break;
                default:
                    *angle = getTheta(other.getPosition()+other.getOffset()-getPosition()-getOffset());
                    break;
                }
                
                return true;
			}
			/*
		case CIRCLE:
			{
				See CircleCollidable::collides
			}
			*/
		default:
			if(other.canCollide(getType()))
            {
                bool ret = other.collides(*this, angle);
                if(angle)
                {
                    *angle += TAO/2.0;
                    angle->validate();
                }
                return ret;
            }
			return false;
        }
    }
	
	const bool CircleCollidable::canCollide(const int t) const
	{
		return t == RECTANGLE || t == POINT || t == CIRCLE;
	}
	
	const bool CircleCollidable::collides(const Collidable& other, Radians * const angle) const
	{
		switch(other.getType())
		{
		case POINT:
            if(angle)
                *angle = getTheta(other.getPosition()-getCenter());
			return pythagoras(getCenter()-other.getPosition()) < radius;
			
		case RECTANGLE:
			{
				Point<double> temp(other.getOffset() + other.getPosition());
				Point<double> corners[4] = {other.getOffset()+other.getPosition(), temp+other.getDimensions(), temp+other.getDimensions().x(), temp+other.getDimensions().y()};
				Point<double> cardinals[4] = {getCenter() + X_t<double>(radius), getCenter() - X_t<double>(radius), getCenter() + Y_t<double>(radius), getCenter() - Y_t<double>(radius)};
				
				for(int i = 0; i < 4; i++)
				{
					if(collides(Collidable(POINT, corners+i), angle))
						return true;
					else if(other.collides(Collidable(POINT, cardinals+i), angle))
                    {
                        if(angle)
                        {
                            *angle += TAO/2.0;
                            angle->validate();
                        }
						return true;
                    }
				}
				
				return false;
			}
		
		case CIRCLE:
        {
			Vector v((other.getPosition() + other.getOffset())-getCenter());
            if(angle)
                *angle = v.theta();
            return v.mag() < other.getDimensions().x()+radius;
        }
			
		default:
			if(other.canCollide(getType()))
            {
                bool ret = other.collides(*this, angle);
                if(angle)
                {
                    *angle += TAO/2.0;
                    angle->validate();
                }
                return ret;
            }
			return false;
		}
	}
}