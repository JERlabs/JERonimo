#include "Velocity.h"

namespace Space2D {

Velocity::Velocity (long double const &M, long double const &T): Vector(M, T), Point(Vector(M, T)) {
}

Velocity::Velocity (Point const &p2): Vector(p2), Point(p2) {
          /*Just point constructor function call ^ */   /*  ^ Parent class constructor call   */
}

Velocity::Velocity (Vector const &v2): Point(v2), Vector(v2) {
}

const long double Velocity::x() const {
  return X;
}

const long double Velocity::y() const {
  return Y;
}

const long double Velocity::x(const long double &x) {
  X = x;
  Vector(X,Y);
  return X;
}

const long double Velocity::y(const long double &y) {
  Y = y;
  Vector(X,Y);
  return Y;
}

const long double Velocity::mag() const {
  return Mag;
}

const long double Velocity::theta() const {
  return Theta;
}

const long double Velocity::mag(const long double &m) {
  (X /= Mag) *= m;
  Mag = m;
  return Mag;
}

const long double Velocity::theta(const long double &t) {
  long double ct = cos(t);
  long double st = sin(t);
  X = (X*ct - Y*st);
  int x(X);
  Y = (x*st + Y*ct);
  Theta = t;
  return Mag;
}

}
