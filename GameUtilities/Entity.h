#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>

#include "ControlInterfaces/Displayable.h"
#include "Space2D/Point.h"
#include "SDLWrappers/Blittable.h"

namespace jer
{
    using std::shared_ptr;
    
    class Entity: public virtual Displayable
    {
    private:
        shared_ptr<const Blittable> image;
		
	protected:
        mutable Point<int> position;
        
    public:
        virtual ~Entity() {};
        Entity(const shared_ptr<const Blittable> img, const Point<int> &p): image(img), position(p) {};
        Entity(const Blittable * const img, const Point<int> &p): image(img), position(p) {};
        Entity(const shared_ptr<const Blittable> img): image(img) {};
        Entity(const Blittable * const img): image(img) {};
        Entity(const Point<int> &p): Entity(nullptr, p) {};
        Entity(const Entity& other): image(other.image), position(other.position) {};
        Entity() {};
        Entity& operator= (const Entity &other);
        
    public:
        virtual const Point<int> getPixelPosition() const {return position;};
        void setPixelPosition(const Point<int> &p) {position = p;};
        const shared_ptr<const Blittable> getImage() const {return image;};
        void setImage(const shared_ptr<const Blittable> img) {image = img;};
        void setImage(const Blittable * const img) {setImage(shared_ptr<const Blittable>(img));};
        
    public:
        virtual const SUCCESS display() const override;
    };
}



#endif /*_ENTITY_H_*/