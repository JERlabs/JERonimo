#include "Velocity.h"

namespace Space2D {

Point &Velocity::x(const X_t &x) {
  X = x;
  Mag = pythagoras(X, Y);
  Theta = getTheta(X, Y);
  return *this;
}

Point &Velocity::y(const Y_t &y) {
  Y = y;
  Mag = pythagoras(X, Y);
  Theta = getTheta(X, Y);
  return *this;
}

Vector &Velocity::mag(const Mag_t &m) {
  X /= Mag;
  X *= m;
  Y /= Mag;
  Y *= m;
  Mag = m;
  return *this;
}

Vector &Velocity::theta(const Radians &t) {
  X = getX(Mag, t);
  Y = getY(Mag, t);
  Theta = t;
  return *this;
}

}
