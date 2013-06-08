#include "Point.h"
#include "Vector.h"

namespace Space2D {
  Vector::Vector(long double const &mag, long double const &theta): Mag(mag), Theta(theta) {
  }

  Vector::Vector(Vector const &v2) {
    Mag = v2.mag();
    Theta = v2.theta();
  }

  Vector::Vector(Point const &p2) {
    Mag = sqrt(p2.x()*p2.x() + p2.y()*p2.y());
    if(p2.x() == 0) {
      if(p2.y() > 0)
        Theta = ANGLE_UP;
      else if(p2.y() < 0)
        Theta = ANGLE_DOWN;
      else
        return;
    }
    else if(p2.x() < 0) {
      Theta = 180 + atan(p2.y()/p2.x());
    }
    else {
      Theta = atan(p2.y()/p2.x());
    }
  }

  const long double Vector::mag() const {
    return Mag;
  }

  const long double Vector::mag(const long double &m) {
    return Mag = m;
  }

  const long double Vector::theta() const {
    return Theta;
  }

  const long double Vector::theta(const long double &t) {
    return Theta = t;
  }

  Point const Vector::operator+ (Point const& p2) const {
    return (Point)*this + p2;
  }

  Point const Vector::operator- (Point const& p2) const {
    return (Point)*this - p2;
  }

  Point const Vector::operator* (const long double& scale) const {
    return (Point)*this * scale;
  }

  Point const Vector::operator/ (const long double& scale) const {
    return (Point)*this / scale;
  }

  Vector& Vector::operator= (Vector const &v2) {
    Mag = v2.mag();
    Theta = v2.theta();
    return *this;
  }

  Vector& Vector::operator+= (Point const &p2) {
    return *this = *this + p2;
  }

  Vector& Vector::operator-= (Point const &p2) {
    return *this = *this - p2;
  }

  Vector& Vector::operator*= (const long double &scale) {
    return *this = *this * scale;
  }

  Vector& Vector::operator/= (const long double &scale) {
    return *this = *this / scale;
  }

  const bool Vector::operator== (Vector const &v2) const {
    return (Mag == v2.mag()) && (Theta == v2.theta());
  }

  const bool Vector::operator!= (Vector const &v2) const {
    return !(*this == v2);
  }

}
