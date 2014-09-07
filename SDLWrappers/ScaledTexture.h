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
        Texture *preload;
        
    public:
        virtual ~ScaledTexture() {};
        ScaledTexture(const Texture& other, const Dimensions<int> &d, const Point<int> &o): Texture(other), offset(o), size(d), preload(NULL) {};
        ScaledTexture(const Texture& other, const Dimensions<int> &d): ScaledTexture(other, d, d/-2) {};
        ScaledTexture(const Texture& other): ScaledTexture(other, other.getDim()) {};
        
        ScaledTexture(Texture * const other, const Dimensions<int> &d, const Point<int> &o): Texture(nullptr, NULL), offset(o), size(d), preload(other) {};
        ScaledTexture(Texture * const other, const Dimensions<int> &d): ScaledTexture(other, d, d/-2) {};
        ScaledTexture(Texture * const other): ScaledTexture(other, other->getDim()) {};
        
    public:
        void setDim(const Dimensions<int> &d) {size = d;};
        void setOffset(const Point<int> &o) {offset = o;};
        
    public:
        virtual const Dimensions<int> getDim() const override {return size;};
        virtual const Point<int> getOffset() const override {return offset;};
        virtual const SUCCESS load() override {if(preload) {const SUCCESS ret = preload->load(); this->Texture::operator=(*preload); return ret;} else return Texture::load();};
    };
}


#endif /*_SCALED_TEXTURE_H_*/