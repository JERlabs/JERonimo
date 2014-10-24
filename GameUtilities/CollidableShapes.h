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
        virtual const bool collides(const Collidable &other, Radians * const angle=NULL) const override;
        virtual RectangleCollidable * const clone() const override {return new RectangleCollidable(box, getPositionRef());};
        
    public:
        virtual const bool collidesPoint(const Point<double> p) const override;
    };
	
	class CircleCollidable: public Collidable
	{
	private:
		Point<double> offset;   /// Offset of the center of the circle from the center of the image
		Scalar<double> radius;  /// The radius of the collision box
		
	public:
		virtual ~CircleCollidable() {};
		CircleCollidable(const Point<double> &off, const Scalar<double> &r, const Point<double> * const p=NULL): Collidable(CIRCLE, p), offset(off), radius(r) {};
		
	public:
		virtual const Point<double> getOffset() const override {return offset;};
		virtual const Dimensions<double> getDimensions() const override {return Dimensions<double>(radius, 0.0);};
		virtual void setOffset(const Point<double> &off) override {offset = off;};
		virtual void setDimensions(const Dimensions<double> &dim) override {radius = dim.x();};
		
	protected:
		const Point<double> getCenter() const {return offset+getPosition();};
		
	public:
		virtual const bool canCollide(const int t) const override;
		virtual const bool collides(const Collidable &other, Radians * const angle=NULL) const override;
		virtual CircleCollidable * const clone() const override {return new CircleCollidable(offset, radius, getPositionRef());};
	};
}


#endif /*_COLLIDABLE_SHAPES_H_*/