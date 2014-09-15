#include "PhysicalEntity.h"

namespace jer
{
    const SUCCESS PhysicalEntity::loop()
    {
		if(physics != nullptr)
		{
			const SUCCESS ret = physics->loop();
			setPixelPosition(physics->getPosition());
			return ret;
		}
    }
}