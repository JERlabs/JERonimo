#ifndef _POINT_H_
#define _POINT_H_

namespace Space2D {

class Point {
  private:
    long double X;
    long double Y;
  public:
    Point (long double const&, long double const&);
    Point (Point const&);
    long double x() const;
    long double x(long double const&);
    long double y() const;
    long double y(long double const&);
    Point const operator + (Point const&) const;
    Point const operator - (Point const&) const;
    Point const operator * (long double const&) const;
    Point const operator / (long double const&) const;
    Point& operator = (Point const&);
    Point& operator += (Point const&);
    Point& operator -= (Point const&);
    Point& operator *= (long double const&);
    Point& operator /= (long double const&);
    bool operator == (Point const&) const;
    bool operator != (Point const&) const;
};

}
#endif
