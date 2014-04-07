#include "Point.h"
#include "Vector.h"

namespace jer {
  
Vector::Vector(const Point &p2): Mag(pythagoras(p2)), Theta(getTheta(p2)) {
}

Vector& Vector::mag(const Mag_t &m) {
  Mag = m;
  return *this;
}

Vector& Vector::setMag(const PIXEL_TYPE &m) {
  Mag.val = m;
  return *this;
}

Vector& Vector::theta(const Radians &t) {
  Theta = t;
  return *this;
}

Vector& Vector::operator= (Vector const &v2) {
  Mag = v2.mag();
  Theta = v2.theta();
  return *this;
}

Vector& Vector::operator+= (Point const &p2) {
  Mag = pythagoras(p2.x() + getX(*this), p2.y() + getY(*this));
  Theta = getTheta(p2.x() + getX(*this), p2.y() + getY(*this));
  return *this;
}

Vector& Vector::operator-= (Point const &p2) {
  Mag = pythagoras(getX(*this) - p2.x(), getY(*this) - p2.y());
  Theta = getTheta(getX(*this) - p2.x(), getY(*this) - p2.y());
  return *this;
}

Vector& Vector::operator*= (const PIXEL_TYPE &scale) {
  Mag *= scale;
  return *this;
}

Vector& Vector::operator/= (const PIXEL_TYPE &scale) {
  Mag /= scale;
  return *this;
}


}
