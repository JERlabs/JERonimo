#ifndef _PHYSICS_ENGINE_H_
#define _PHYSICS_ENGINE_H_

#include "ControlInterfaces/LoopEngine.h"
#include "PhysicalObject.h"

namespace jer
{
	class PhysicsEngine: public LoopEngine<PhysicalObject *>
	{
	public:
		virtual const SUCCESS loop() override;
	};
}



#endif /*_PHYSICS_ENGINE_H_*/