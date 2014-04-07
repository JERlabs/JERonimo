#ifndef _VELOCITY_H_
#define _VELOCITY_H_
#include "Vector.h"

namespace jer {

class Velocity: virtual Point, virtual Vector {
  public:
    using Point::x;
    using Point::y;
    using Vector::mag;
    using Vector::theta;
    /// Create a velocity from an angle and magnitude
    Velocity(const Mag_t &M, const Radians &T): Vector(M, T), Point(Vector(M, T)) {};
    
    /// Create a velocity from an X and Y
    Velocity(const X_t &x, const Y_t &y): Point(x, y), Vector(Point(x, y)) {};
    
    /// Create a velocity from a point
    Velocity (Point const &p2): Vector(p2), Point(p2) {
          /*Just point constructor function call ^ */   /*  ^ Parent class constructor call   */
    };
    
    /// Create a velocity from a vector
    Velocity (Vector const &v2): Vector(v2), Point(v2) {};
    
    /// Set and return the x-coordinate
    Point &x(const X_t &x);
        
    /// Set and return the y coordinate
    Point &y(const Y_t &y);
    
    /// Set and return magnitude
    Vector &mag(const Mag_t &m);
    
    Vector &setMag(const PIXEL_TYPE &m){
      return mag(Mag_t(m));
    };
    
    /// Set and return angle
    Vector &theta(const Radians &theta);

    /// Adds vv2 to the velocity and returns a reference to it
    Velocity const& operator+= (Velocity const& vv2) {
      X += vv2.x();
      Y += vv2.y();
      Mag = pythagoras(X, Y);
      Theta = getTheta(X, Y);
      return *this;
    };

    /// Subtracts vv2 from the velocity
    Velocity const& operator-= (Velocity const& vv2) {
      X -= vv2.x();
      Y -= vv2.y();
      Mag = pythagoras(X, Y);
      Theta = getTheta(X, Y);
      return *this;
    };

    /// Multiplies the magnitude and x-y of the velocity by scale
    Velocity const& operator*= (const PIXEL_TYPE &scale) {
      X *= scale;
      Y *= scale;
      Mag *= scale;
      return *this;
    };

    /// Divides the magnitude and x-y of the velocity by scale
    Velocity const& operator/= (const PIXEL_TYPE &scale) {
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
    
    /// Construct and return sum of of this velocity and vv2
    inline Velocity const operator+ (Velocity const& vv1, Velocity const& vv2) {
      return Velocity(vv1) += vv2;
    }

    /// Construct and return difference between this velocity and vv2
    inline Velocity const operator- (Velocity const& vv1, Velocity const& vv2) {
      return Velocity(vv1) += vv2;
    }

    /// Construct and return the velocity with the magnitude and coordinates multiplied by scale
    inline Velocity const operator* (Velocity const &vv1, const PIXEL_TYPE& scale) {
      return Velocity(vv1) *= scale;
    }
    
    inline Velocity const operator* (const PIXEL_TYPE& scale, Velocity const &vv1) {
      return vv1*scale;
    }
    
    /// Construct and return the velocity with the magnitude and coordinates divided by scale
    inline Velocity const operator/ (Velocity const& vv1, const PIXEL_TYPE& scale) {
      return Velocity(vv1) /= scale;
    }

}
#endif