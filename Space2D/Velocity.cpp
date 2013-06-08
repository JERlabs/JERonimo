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

const long double Velocity::x(const long double &X) {
  this->X = X;
  (Vector)*this = (Point)*this;
  return X;
}

const long double Velocity::y(const long double &Y) {
  this->Y = Y;
  (Vector)*this = (Point)*this;
  return Y;
}

const long double Velocity::mag() const {
  return Mag;
}

const long double Velocity::theta() const {
  return Theta;
}

const long double Velocity::mag(const long double &m) {
  Mag = m;
  (Point)*this = (Vector)*this;
  return Mag;
}

const long double Velocity::theta(const long double &t) {
  Theta = t;
  (Point)*this = (Vector)*this;
  return Mag;
}

}