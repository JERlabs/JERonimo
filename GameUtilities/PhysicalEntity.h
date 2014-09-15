#ifndef _PHYSICAL_ENTITY_H_
#define _PHYSICAL_ENTITY_H_

#include <memory>

#include "Entity.h"
#include "PhysicalObject.h"


namespace jer
{
	
    class PhysicalEntity: public Entity, public Loopable
    {
	private:
		shared_ptr<PhysicalObject> physics;
    public:
        virtual ~PhysicalEntity() {};
        PhysicalEntity(const shared_ptr<const Blittable> img, const shared_ptr<PhysicalObject> objPart): 
                       Entity(img, objPart != nullptr? objPart->getPosition():Point<double>(0.0, 0.0)), physics(objPart) {}
        PhysicalEntity(const Blittable * const img, PhysicalObject * const objPart):
                       PhysicalEntity(shared_ptr<const Blittable>(img), shared_ptr<PhysicalObject>(objPart)) {};
        PhysicalEntity(PhysicalObject * const objPart): PhysicalEntity(NULL, objPart) {};
        PhysicalEntity(const PhysicalEntity& other): Entity(other), physics(other.physics->clone()) {};
        PhysicalEntity() {};
        
	public:
		const shared_ptr<PhysicalObject> getPhysicalObject() {return physics;};
		void setPhysicalObject(PhysicalObject * const phys) {physics.reset(phys);};
		void setPhysicalObject(const shared_ptr<PhysicalObject> phys) {physics = phys;};
		virtual const Point<int> getPixelPosition() const override {return physics == nullptr? position:(position = physics->getPosition());};
		
    public:
        virtual const SUCCESS loop() override;
    };
}

#endif  /*_PHYSICAL_ENTITY_H_*/