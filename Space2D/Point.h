#ifndef _POINT_H_
#define _POINT_H_

#include "Space2D.h"

namespace Space2D {

class Point {
  private:
    long double X;
    long double Y;
  public:
    Point (long double const& xInit, long double const& yInit);
    Point (Point const& p2);
	Point (Vector const& v2);
	Point ();
    const long double x() const;
    const long double x(long double const&);
    const long double y() const;
    const long double y(long double const&);
    Point const operator + (Point const&) const;
    Point const operator - (Point const&) const;
    Point const operator * (long double const&) const;
    Point const operator / (long double const&) const;
    Point& operator = (Point const&);
    Point& operator += (Point const&);
    Point& operator -= (Point const&);
    Point& operator *= (long double const&);
    Point& operator /= (long double const&);
    const bool operator == (Point const&) const;
    const bool operator != (Point const&) const;
};

}
#endif
