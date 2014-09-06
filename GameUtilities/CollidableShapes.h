#ifndef _COLLIDABLE_SHAPES_H_
#define _COLLIDABLE_SHAPES_H_

#include "Collidable.h"
#include "SDLWrappers/Drawable.h"

namespace jer
{
    class RectangleCollidable: public Collidable
    {
    private:
        Rectangle<double> box;   /// Position is an offset of the position of the box
        
    public:
        virtual ~RectangleCollidable() {};
        RectangleCollidable(const Rectangle<double> b, const Point<double> * const p=NULL): Collidable(RECTANGLE, p), box(b) {};
        
    public:
        virtual const Point<double> getOffset() const override {return box.position;};
        virtual const Dimensions<double> getDimensions() const override {return box.size;};
        virtual void setOffset(const Point<double> &off) override {box.position = off;};
        virtual void setDimensions(const Dimensions<double> &dim) override {box.size = dim;};
        
	protected:
		const Point<double> getTopLeft() const {return box.position + getPosition();};
		const Point<double> getBottomRight() const {return getTopLeft() + box.size;};
		const Point<double> getBottomLeft() const {return getTopLeft() + box.size.y();};
		const Point<double> getTopRight() const {return getTopLeft() + box.size.x();};
		
    public:
        virtual const bool canCollide(const int t) const override;
        virtual const bool collides(const Collidable &other) const override;
        virtual Collidable * const copy() const override {return new RectangleCollidable(box, getPositionRef());};
    };
}


#endif /*_COLLIDABLE_SHAPES_H_*/