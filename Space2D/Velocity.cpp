#include "Velocity.h"

namespace Space2D {

Velocity::Velocity (long double const &x, long double const &y) {
  Point(x,y);
  Vector(Point);
}

Velocity::Velocity (Point const &p2) {
  Vector(Point(p2));
}

Velocity::Velocity (Vector const &v2) {
  Point(Vector(v2));
}
}
