#ifndef _BLITTABLE_H_
#define _BLITTABLE_H_

#include "Declarations.h"
#include "Drawable.h"

namespace jer
{
    class Blittable
    {
    public:
        virtual ~Blittable() {};
        Blittable() {};
        
    public:
        virtual const SUCCESS blit(const Rectangle<int> &src, const Rectangle<int> &dst) const {return FAILED;};
        virtual const SUCCESS blit(const Rectangle<int> &dst) const {return FAILED;};
        virtual const SUCCESS blit(const Point<int> &dst) const {return FAILED;};
    };
}


#endif /*_BLITTABLE_H_*/