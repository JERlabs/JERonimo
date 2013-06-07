#ifndef _POINT_H_
#define _POINT_H_

namespace Space2D {

class Point {
  private:
    long double X;
    long double Y;
  public:
    Point (long double const&, long double const&);
    long double x();
    long double x(long double const&);
    long double y();
    long double y(long double const&);
    Point operator + (Point &);
    Point operator - (Point &);
    Point operator * (long double const&);
    Point operator / (long double const&);
    Point operator += (Point &);
    Point operator -= (Point &);
    Point operator *= (long double const&);
    Point operator /= (long double const&);
    bool operator == (Point &);
    bool operator != (Point &);
};

}
#endif
