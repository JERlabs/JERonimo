#ifndef _DRAWABLE_H_
#define _DRAWABLE_H_

#include "Declarations.h"

namespace jer
{
    class Color
    {
    public:
        typedef unsigned char VAL;
        
    private:
        VAL r, g, b;
        
    public:
        Color(const VAL ir=0, const VAL ig=0, const VAL ib=0): r(ir), g(ig), b(ib) {};
        Color(const Color& other): r(other.r), g(other.g), b(other.b) {};
        
    public:
        VAL& R() {return r;};
        VAL& G() {return g;};
        VAL& B() {return b;};
        const VAL& R() const {return r;};
        const VAL& G() const {return g;};
        const VAL& B() const {return b;};
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
    };
    
    
    class Drawable
    {
    public:
        virtual setColor(const Color& c)=0;
        virtual drawPoint(const Point<unsigned int> &p)=0;
        virtual drawLine(const Point<unsigned int>& p1, const Point<unsigned int>& p2)=0;
        virtual drawRect(const Point<unsigned int>&
    };
}


#endif /*_DRAWABLE_H_*/