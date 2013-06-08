#ifndef _VELOCITY_H_
#define _VELOCITY_H_
#include "Point.h"
#include "Vector.h"

namespace Space2D {

class Velocity: virtual Point, virtual Vector {
  public:
    /// Create a velocity from an angle and magnitude
    Velocity(long double const &mag, long double const &theta);
    
    /// Create a velocity from a point
    Velocity(Point const &p2);
    
    /// Create a velocity from a vector
    Velocity(Vector const &v2);
    
    /// Return the x coordinate
    long double const x() const;
    
    /// Set and return the x coordinate
    long double const x(long double const &x);
    
    /// Return the y coordinate
    long double const y() const;
    
    /// Set and return the y coordinate
    long double const y(long double const &x);
    
    /// Return magnitude
    long double const mag() const;
    
    /// Set and return magnitude
    long double const mag(long double const &mag);
    
    /// Return angle
    long double const theta() const;
    
    /// Set and return angle
    long double const theta(long double const &theta);

    Velocity const operator+ (Velocity const& vv2) const {
      return Velocity(*this) += vv2;
    };

    Velocity const operator- (Velocity const& vv2) const {
      return Velocity(*this) += vv2;
    };

    Velocity const operator* (const long double& scale) const {
      return Velocity(*this) *= scale;
    };
    
    Velocity const operator/ (const long double& scale) const {
      return Velocity(*this) /= scale;
    };

    Velocity const operator+= (Velocity const& vv2) {
      X += vv2.x();
      Y += vv2.y();
      Vector(X,Y);
      return *this;
    };

    Velocity const operator-= (Velocity const& vv2) {
      X -= vv2.x();
      Y -= vv2.y();
      Vector(X,Y);
      return *this;
    };

    Velocity const operator*= (const long double &scale) {
      X *= scale;
      Y *= scale;
      Mag *= scale;
      return *this;
    };

    Velocity const operator/= (const long double &scale) {
      X /= scale;
      Y /= scale;
      Mag /= scale;
      return *this;
    };

    const bool operator== (const Velocity& comp) const {
      return (X == comp.x())&&(Y == comp.y());
    };

    const bool operator!= (const Velocity& comp) const {
      return !(*this == comp);
    };
};

}
#endif

