#include "Entity.h"

namespace jer
{
    Entity& Entity::operator= (const Entity &other)
    {
        image = other.image;
        position = other.position;
        return *this;
    }
    
    const SUCCESS Entity::display() const
    {
        return image->blit(position);
    }
}