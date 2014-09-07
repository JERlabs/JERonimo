#include "PhysicsEngine.h"

namespace jer
{
	const SUCCESS PhysicsEngine::loop()
	{
		SUCCESS ret = 0;
		for(unsigned int i = getFirst(); i < getLast(); i++)
		{
			for(int j = i+1; j < getLast(); j++)
			{
				loopList->at(i)->gravitate(*loopList->at(j));
				loopList->at(j)->gravitate(*loopList->at(i));
				ret |= loopList->at(i)->checkCollision(*loopList->at(j));
			}
		}
		
		return ret | LoopEngine<PhysicalObject *>::loop();
	}
}