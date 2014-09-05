#ifndef _COLLIDABLE_H_
#define _COLLIDABLE_H_

#include "Space2D.h"

namespace jer
{
    class Collidable
    {
    public:
        enum {NONE=0, RECTANGLE=-1, CIRCLE=-2};
        
    private:
        int type;
        
    public:
        virtual ~Collidable() {};
        Collidable(const int t = NONE): type(t) {};
        Collidable(const Collidable &other): type(other.type) {};
        
    public:
        const int getType() const {return type;};
        
    protected:
        void setType(const int t) {type = t;};  /// Protected so that data doesn't become invalidated by a call to setType from outside the object but through the data part of the object
        
    public:
        virtual const Point<double> getVertex() const=0;
        virtual const Dimensions<double> getDimensions() const {return Dimensions<double>(0.0, 0.0);};
        virtual const Scalar<double> getData(const int index) const {return 0.0;};
        
        virtual void setVertex(const Point<double> &vertRef) {};
        virtual void setDimensions(const Dimensions<double> &dimRef) {};
        virtual void setData(const int index, const Scalar<double> &dataRef) {};
        
    public:
        virtual const bool canCollide(const int t) const {return false;};
        virtual const bool collides(const Collidable &other) const {if(other.canCollide(type)) return other.collides(*this);};
        virtual Collidable * const copy() const=0;
    };
}


#endif /*_COLLIDABLE_H_*/