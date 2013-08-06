#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Point.h"

namespace Space2D
{

class Vector {
  protected:
    /// Magnitude of the vector
    Mag_t Mag;
    
    /// Angle of the vector
    Radians Theta;
    
  public:
    /// Create a vector from a magnitude and angle
    Vector(const Mag_t &mag, const Radians &theta): Mag(mag), Theta(theta) {};
    
    /// Create a vector from another vector
    Vector(Vector const &v2): Mag(v2.Mag), Theta(v2.Theta) {};
    
    /// Create a vector from a Point
    Vector(const Point &p2);
    
    /// Create a vector with default values
    Vector(): Mag(1), Theta() {};
    
  public:
    /// Returns the magnitude of the vector
    const Mag_t &mag() const {
      return Mag;
    };
    
    /// Sets the magnitude of the vector to m, returns new magnitude.
    virtual Vector& mag(const Mag_t &m);
    
    /// Returns the angle of the vector
    const Radians &theta() const {
      return Theta;
    };
    
    /// Sets the angle of the vector to t, returns new angle
    virtual Vector &theta(const Radians &t);
    
  public:
    /// Sets the magnitude and angle of the vector to that of another
    Vector& operator = (Vector const& v2);
    
    /// Adds the vector to a point
    Vector& operator += (Point const& p2);
    
    /// Subtracts a point from the vector
    Vector& operator -= (Point const& p2);
    
    /// Scales the vector by scale
    Vector& operator *= (const PIXEL_TYPE &scale);
    
    /// Scales the vector by scale
    Vector& operator /= (const PIXEL_TYPE &scale);
    
    /// Checks for equality of two vectors
    const bool operator == (Vector const &v2) const {
      return Mag == v2.mag() && Theta == v2.theta();
    };
    
    /// Checks for inequality of two vectors
    const bool operator != (Vector const &v2) const {
      return !(*this == v2);
    };
  };
  
  inline const Vector& operator * (const Vector& lhs, const PIXEL_TYPE &rhs) {
    return Vector(lhs) *= rhs;
  }
  
  inline const Vector& operator * (const PIXEL_TYPE &lhs, const Vector& rhs) {
    return rhs * lhs;
  }
  
  inline const Vector& operator / (const Vector& lhs, const PIXEL_TYPE &rhs) {
    return Vector(lhs) /= rhs;
  }
  
  inline const PIXEL_TYPE getX(const Vector& v) {
    return v.mag() * cos(v.theta());
  }
  
  inline const PIXEL_TYPE getY(const Vector& v) {
    return v.mag() * sin(v.theta());
  }

}

#endif
