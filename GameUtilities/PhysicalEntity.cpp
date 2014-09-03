#include "PhysicalEntity.h"

namespace jer
{
    const SUCCESS PhysicalEntity::loop()
    {
        const SUCCESS ret = PhysicalObject::loop();
        setPixelPosition(getPosition());
        return ret;
    }
}