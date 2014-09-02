#ifndef _SCALED_TEXTURE_H_
#define _SCALED_TEXTURE_H_

#include "Texture.h"

namespace jer
{
    class ScaledTexture: public Texture
    {
    private:
        Dimensions<int> size;
        
    public:
        virtual ~ScaledTexture() {};
        ScaledTexture(const Texture& other, const Dimensions<int> &d): Texture(other), size(d) {};
        ScaledTexture(const Texture& other): ScaledTexture(other, other.getDim()) {};
        
    public:
        void setDim(const Dimensions<int> &d) {size = d;};
        
    public:
        virtual const Dimensions<int> getDim() const override {return size;};
    };
}


#endif /*_SCALED_TEXTURE_H_*/