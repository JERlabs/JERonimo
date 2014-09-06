#ifndef _COLLIDABLE_SHAPES_H_
#define _COLLIDABLE_SHAPES_H_

#include "Collidable.h"
#include "SDLWrappers/Drawable.h"

namespace jer
{
    class RectangleCollidable: public Collidable
    {
    private:
        const Point<double> *point;
        const Dimensions<double> *dim;
        const bool erasePoint;
        const bool eraseDim;
        
    public:
        virtual ~RectangleCollidable();
        RectangleCollidable(const Rectangle<double> d): Collidable(RECTANGLE), point(new Point<double>(d.position)), dim(new Dimensions<double>(d.size)), erasePoint(true), eraseDim(true) {};
        RectangleCollidable(const Point<double> * const p, const Point<double> * const): Collidable(RECTANGLE), point(p), dim(d), erasePoint(false), eraseDim(false) {};
        
    public:
        virtual const Point<double> getVertex() const override {return *point;};
        virtual const Dimensions<double> getDimensions() const override {return *dim;};
        virtual void setVertex(const Point<double> * const vertRef) override;
        virtual void setDimensions(const Dimensions<double> * const dimRef) override;
        
    public:
        virtual const bool canCollide(const int t) const override;
        virtual const bool collides(const Collidable &other) const override;
        virtual Collidable * const copy() const override;
    };
}


#endif /*_COLLIDABLE_SHAPES_H_*/