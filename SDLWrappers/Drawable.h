#ifndef _DRAWABLE_H_
#define _DRAWABLE_H_

#include "Declarations.h"
#include "Space2D/Point.h"

namespace jer
{
    class Color
    {
    public:
        typedef unsigned char VAL;
        
    private:
        VAL r, g, b, a;
        
    public:
        Color(const VAL ir=0, const VAL ig=0, const VAL ib=0, const VAL ia=0): r(ir), g(ig), b(ib), a(ia) {};
        Color(const Color& other): r(other.r), g(other.g), b(other.b), a(other.a) {};
        
    public:
        VAL& R() {return r;};
        VAL& G() {return g;};
        VAL& B() {return b;};
        VAL& A() {return a;};
        const VAL& R() const {return r;};
        const VAL& G() const {return g;};
        const VAL& B() const {return b;};
        const VAL& A() const {return a;};
    };
    
    template<class T>
    class Line
    {
    public:
        Point<T> p1, p2;
        
    public:
        Line(const Point<T> &ip1, const Point<T> &ip2): p1(ip1), p2(ip2) {};
        Line(const Line<T> &other): p1(other.p1), p2(other.p2) {};
        Line() {};
        Line<T> &operator=(const Line<T>& other) {p1 = other.p1; p2 = other.p1; return *this;};
        
    public:
        const bool operator== (const Line<T> &other) const {return this->p1 == other.p1 && this->p2 == other.p2;};
    };
    
    template<class T>
    class Rectangle
    {
    public:
        Point<T> position;
        Dimensions<T> size;
        
    public:
        operator const SDL_Rect() const
        {
            SDL_Rect ret;
            if(size.x() < 0)
            {
                ret.x = position.x() + size.x();
                ret.w = -size.x();
            }
            else
            {
                ret.x  = position.x();
                ret.w = size.x();
            }
            if(size.y() < 0)
            {
                ret.y = position.y() + size.y();
                ret.h = -size.y();
            }
            else
            {
                ret.y = position.y();
                ret.h = size.y();
            }
            
            return ret;
        };
        
        operator const Line<T>() const
        {
            return Line<T>(position, position+size);
        };
        
    public:
        Rectangle(const Point<T> &p, const Dimensions<T> &s): position(p), size(s) {};
        Rectangle(const Rectangle<T> &other): position(other.position), size(other.size) {};
        Rectangle(const Line<T> &l): position(l.p1), size(l.p2-l.p1) {};
        Rectangle() {};
        Rectangle<T> &operator=(const Rectangle<T>& other) {position = other.position; size = other.size; return *this;};
        
    public:
        const bool operator== (const Rectangle<T> &other) const {return this->position == other.position && this->size == other.size;};
        const Scalar<Scalar<T> > area() const {return abs(size.x()*size.y());};
    };
    
    class Drawable
    {
    public:
        enum {NONE=SDL_BLENDMODE_NONE, BLEND=SDL_BLENDMODE_BLEND, ADD=SDL_BLENDMODE_ADD, MOD=SDL_BLENDMODE_MOD};
        
    public:
        virtual const SUCCESS setColor(const Color& c)=0;
        virtual const Color getColor() const=0;
        virtual const SUCCESS setBlendMode(const Uint8 mode)=0;
        virtual const Uint8 getBlendMode() const=0;
        virtual const SUCCESS drawPoint(const Point<int> &p)=0;
        virtual const SUCCESS drawLine(const Line<int> &line)=0;
        virtual const SUCCESS drawRect(const Rectangle<int> &rect)=0;
        virtual const SUCCESS fillRect(const Rectangle<int> &rect)=0;
    };
}


#endif /*_DRAWABLE_H_*/