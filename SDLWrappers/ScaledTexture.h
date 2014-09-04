#ifndef _SCALED_TEXTURE_H_
#define _SCALED_TEXTURE_H_

#include "Texture.h"

namespace jer
{
    class ScaledTexture: public Texture
    {
    private:
        Point<int> offset;
        Dimensions<int> size;
        
    public:
        virtual ~ScaledTexture() {};
        ScaledTexture(const Texture& other, const Dimensions<int> &d, const Point<int> &o): Texture(other), offset(o), size(d) {};
        ScaledTexture(const Texture& other, const Dimensions<int> &d): ScaledTexture(other, d, d/-2) {};
        ScaledTexture(const Texture& other): ScaledTexture(other, other.getDim()) {};
        
    public:
        void setDim(const Dimensions<int> &d) {size = d;};
        void setOffset(const Point<int> &o) {offset = o;};
        
    public:
        virtual const Dimensions<int> getDim() const override {return size;};
        virtual const Point<int> getOffset() const override {return offset;};
    };
}


#endif /*_SCALED_TEXTURE_H_*/