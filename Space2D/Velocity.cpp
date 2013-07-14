#include "Velocity.h"

namespace Space2D {

Velocity::Velocity (const PIXEL_TYPE &M, const PIXEL_TYPE &T): Vector(M, T), Point(Vector(M, T)) {
}

Velocity::Velocity (Point const &p2): Vector(p2), Point(p2) {
          /*Just point constructor function call ^ */   /*  ^ Parent class constructor call   */
}

Velocity::Velocity (Vector const &v2): Point(v2), Vector(v2) {
}

const PIXEL_TYPE Velocity::x() const {
  return X;
}

const PIXEL_TYPE Velocity::y() const {
  return Y;
}

const PIXEL_TYPE Velocity::x(const PIXEL_TYPE &x) {
  X = x;
  Vector(X,Y);
  return X;
}

const PIXEL_TYPE Velocity::y(const PIXEL_TYPE &y) {
  Y = y;
  Vector(X,Y);
  return Y;
}

const PIXEL_TYPE Velocity::mag() const {
  return Mag;
}

const PIXEL_TYPE Velocity::theta() const {
  return Theta;
}

const PIXEL_TYPE Velocity::mag(const PIXEL_TYPE &m) {
  (X /= Mag) *= m;
  Mag = m;
  return Mag;
}

const PIXEL_TYPE Velocity::theta(const PIXEL_TYPE &t) {
  PIXEL_TYPE ct = cos(t);
  PIXEL_TYPE st = sin(t);
  X = (X*ct - Y*st);
  int x(X);
  Y = (x*st + Y*ct);
  Theta = t;
  return Mag;
}

}
