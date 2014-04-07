#include "Point.h"
#include "Vector.h"

namespace jer {
  
Point::Point(Vector const &v2): X(getX(v2)), Y(getY(v2)) { 
}

Point& Point::x(const X_t & x) {
  X = x;
  return *this;
}

Point& Point::y(const Y_t & y) {
  Y = y;
  return *this;
}

Point& Point::operator = (Point const &p2) {
  X = p2.x();
  Y = p2.y();
  return *this;
}

Point& Point::operator += (Point const &p2) {
  X += p2.x();
  Y += p2.y();
  return *this;
}

Point& Point::operator += (X_t const &x) {
  X += x;
  return *this;
}

Point& Point::operator += (Y_t const &y) {
  Y += y;
  return *this;
}

Point& Point::operator -= (Point const &p2) {
  X -= p2.x();
  Y -= p2.y();
  return *this;
}

Point& Point::operator -= (X_t const &x) {
  X -= x;
  return *this;
}

Point& Point::operator -= (Y_t const &y) {
  Y -= y;
  return *this;
}

Point& Point::operator *= (const PIXEL_TYPE &scale) {
  X *= scale;
  Y *= scale;
  return *this;
}

Point& Point::operator /= (const PIXEL_TYPE &scale) {
  X /= scale == 0? 1:scale;
  Y /= scale == 0? 1:scale;
  return *this;
}


}
