#ifndef _COLLIDABLE_H_
#define _COLLIDABLE_H_

#include "Space2D.h"

namespace jer
{
    class Collidable
    {
    public:
        enum {POINT=0, RECTANGLE=-1, CIRCLE=-2};
        static const Radians GetCollisionAngle(const Collidable * const c1, const Collidable * const c2);
        
    private:
        int type;
		const Point<double> * position;
        
    public:
        virtual ~Collidable() {};
        Collidable(const int t = POINT, const Point<double> * const p=NULL): type(t), position(p) {};
        Collidable(const Collidable &other): type(other.type), position(other.position) {};
        
    public:
        const int getType() const {return type;};
		const Point<double> getPosition() const {return position == NULL? Point<double>():*position;};
		const Point<double> * const getPositionRef() const {return position;};
		void setPosition(const Point<double> * const p) {position = p;};
        
    protected:
        void setType(const int t) {type = t;};  /// Protected so that data doesn't become invalidated by a call to setType from outside the object but through the data part of the object
        
    public:
        virtual const Point<double> getOffset() const {return Point<double>(0.0, 0.0);};   /// Offset from position
        virtual const Dimensions<double> getDimensions() const {return Dimensions<double>(0.0, 0.0);};   /// Offset from offset
        virtual const Scalar<double> getData(const int index) const {return 0.0;};
        
        virtual void setOffset(const Point<double> &off) {};
        virtual void setDimensions(const Dimensions<double> &dim) {};
        virtual void setData(const int index, const Scalar<double> dataRef) {};
        
    public:
        virtual const bool canCollide(const int t) const {return false;};
        virtual const bool collides(const Collidable &other) const {if(other.canCollide(type)) return other.collides(*this);};
        virtual Collidable * const clone() const {return new Collidable(*this);};
    };
}


#endif /*_COLLIDABLE_H_*/