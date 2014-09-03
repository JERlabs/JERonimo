#ifndef _PHYSICAL_ENTITY_H_
#define _PHYSICAL_ENTITY_H_

#include "Entity.h"
#include "PhysicalObject.h"

namespace jer
{
    class PhysicalEntity: public Entity, public PhysicalObject
    {
    public:
        virtual ~PhysicalEntity() {};
        PhysicalEntity(const shared_ptr<const Blittable> img, const PhysicalObject& objPart): 
                       Entity(img, objPart.getPosition()), PhysicalObject(objPart) {};
        PhysicalEntity(const Blittable * const img, const PhysicalObject& objPart):
                       Entity(img, objPart.getPosition()), PhysicalObject(objPart) {};
        PhysicalEntity(const PhysicalObject& objPart): PhysicalEntity(nullptr, objPart) {};
        PhysicalEntity(const PhysicalEntity& other): Entity(other), PhysicalObject(other) {};
        PhysicalEntity() {};
        
    public:
        virtual const SUCCESS loop() override;
    };
}

#endif  /*_PHYSICAL_ENTITY_H_*/