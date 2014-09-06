#include "Collidable.h"

namespace jer
{
	const Radians Collidable::GetCollisionAngle(const Collidable * const c1, const Collidable * const c2)
	{
		if(c1 == NULL || c2 == NULL)
			return Radians(0.0);

		Radians theta(getTheta(c2->getPosition() - c1->getPosition()));
		if(c1->getType() == RECTANGLE || c2->getType() == RECTANGLE)
		{
			if(theta < TAO/8.0 && theta >= -TAO/8.0)
				return Radians::ANGLE_RIGHT;
			else if(theta >= TAO/8.0 && theta < 3.0*TAO/8.0)
				return Radians::ANGLE_UP;
			else if(theta >= 3.0*TAO/8.0 && theta < 5.0*TAO/8.0)
				return Radians::ANGLE_LEFT;
			else
				return Radians::ANGLE_DOWN;
		}
		else
			return theta;
	}
}