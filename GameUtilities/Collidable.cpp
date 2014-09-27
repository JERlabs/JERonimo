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
            //TODO: Figure out a better way to calculate collision angle, most likely from a more specific return value from collides itself
		}
		else
			return theta;
	}
}