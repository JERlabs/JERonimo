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

    /// Construct and return sum of of this velocity and vv2
    Velocity const operator+ (Velocity const& vv2) const {
      return Velocity(*this) += vv2;
    };

    /// Construct and return difference between this velocity and vv2
    Velocity const operator- (Velocity const& vv2) const {
      return Velocity(*this) += vv2;
    };

    /// Construct and return the velocity with the magnitude and coordinates multiplied by scale
    Velocity const operator* (const long double& scale) const {
      return Velocity(*this) *= scale;
    };
    
    /// Construct and return the velocity with the magnitude and coordinates divided by scale
    Velocity const operator/ (const long double& scale) const {
      return Velocity(*this) /= scale;
    };

    /// Adds vv2 to the velocity and returns a reference to it
    Velocity const& operator+= (Velocity const& vv2) {
      X += vv2.x();
      Y += vv2.y();
      Mag = sqrt(X*X + Y*Y);
      Theta = atan2(X,Y);
      return *this;
    };

    /// Subtracts vv2 from the velocity
    Velocity const& operator-= (Velocity const& vv2) {
      X -= vv2.x();
      Y -= vv2.y();
      Mag = sqrt(X*X + Y*Y);
      Theta = atan2(X,Y);
      return *this;
    };

    /// Multiplies the magnitude and x-y of the velocity by scale
    Velocity const& operator*= (const long double &scale) {
      X *= scale;
      Y *= scale;
      Mag *= scale;
      return *this;
    };

    /// Divides the magnitude and x-y of the velocity by scale
    Velocity const& operator/= (const long double &scale) {
      if(scale == 0.0) return *this;
      X /= scale;
      Y /= scale;
      Mag /= scale;
      return *this;
    };

    // returns true if comp conatins the same x and y component as the velocity
    const bool operator== (const Velocity& comp) const {
      return (X == comp.x())&&(Y == comp.y());
    };

    /// returns true if comp doesn't contain the same x and y component as the velocity
    const bool operator!= (const Velocity& comp) const {
      return !(*this == comp);
    };
};

}
#endif

