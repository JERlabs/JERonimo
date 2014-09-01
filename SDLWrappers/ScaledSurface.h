#ifndef _SCALED_SURFACE_H_
#define _SCALED_SURFACE_H_

#include "Surface.h"
#include "Drawable.h"

namespace jer
{
    class ScaledSurface: public Surface
    {
    private:
        Dimensions<int> size;
        
    public:
        virtual ~ScaledSurface() {};
        ScaledSurface(const Dimensions<int> &d): size(d) {};
        ScaledSurface(const Surface& other, const Dimensions<int> &d): Surface(other), size(d) {resize();};
        ScaledSurface(const Surface& other): Surface(other), size(other.getDim()) {};
        ScaledSurface& operator= (const ScaledSurface &other);
        
    public:
        virtual const SUCCESS load() override;
        const SUCCESS resize(const Dimensions<int> &d);
        const SUCCESS resize() {return resize(size);};
    };
}


#endif /*_SCALED_SURFACE_H_*/