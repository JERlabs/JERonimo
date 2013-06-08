#ifndef _VELOCITY_H_
#define _VELOCITY_H_
#include "Point.h"
#include "Vector.h"

namespace Space2D {

class Velocity: protected Point, protected Vector {
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

    Point const operator+ (Point const& p2) const {
      return (Point)*this + p2;
    };

    Point const operator- (Point const& p2) const {
      return (Point)*this - p2;
    };

    Point const operator* (const long double& scale) const {
      return (Point)*this * scale;
    };

    Point const operator/ (const long double& scale) const {
      return (Point)*this / scale;
    };

    Point const operator+= (Point const& p2) const {
      (Vector)*this = ((Point)*this += p2);
      return *this;
    };

    Point const operator-= (Point const& p2) const {
      (Vector)*this = ((Point)*this -= p2);
      return *this;
    };

    Point const operator*= (const long double &scale) const {
      (Vector)*this = ((Point)*this *= scale);
      return *this;
    };

    Point const operator/= (const long double &scale) const {
      (Vector)*this = ((Point)*this /= scale);
      return *this;
    };

    const bool operator== (const Point& comp) const {
      return (Point)*this == comp;
    };

    const bool operator!= (const Vector& comp) const {
      return (Point)*this != comp;
    };
};

}
#endif

