#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Space2D.h"

namespace Space2D
{

class Vector {
  protected:
    /// Magnitude of the vector
    long double Mag;
    
    /// Angle of the vector
    long double Theta;
  public:
    /// Create a vector from a magnitude and angle
    Vector(long double const &mag, long double const &theta);
    
    /// Create a vector from another vector
    Vector(Vector const &v2);	
    
    /// Create a vector from a point
    Vector(const Point &p2);
    
    /// Create a vector with default values
    Vector();
  public:
    /// Returns the magnitude of the vector
    const long double mag() const;
    
    /// Sets the magnitude of the vector to m, returns new magnitude.
    const long double mag(const long double &m);
    
    /// Returns the angle of the vector
    const long double theta() const;
    
    /// Sets the angle of the vector to t, returns new angle
    const long double theta(const long double &t);
  public:
    /// Adds a point and a vector
    Point const operator + (Point const& p2) const;
    
    /// Subtracts a point from a vector
    Point const operator - (Point const& p2) const;
    
    /// Returns the vector as a point scaled by scale
    Vector const operator * (const long double &scale) const;
    
    /// Returns the vector as a point scaled by 1/scale
    Vector const operator / (const long double &scale) const;
    
    /// Sets the magnitude and angle of the vector to that of another
    Vector& operator = (Vector const& v2);
    
    /// Adds the vector to a point
    Vector& operator += (Point const& p2);
    
    /// Subtracts a point from the vector
    Vector& operator -= (Point const& p2);
    
    /// Scales the vector by scale
    Vector& operator *= (const long double &scale);
    
    /// Scales the vector by scale
    Vector& operator /= (const long double &scale);
    
    /// Checks for equality of two vectors
    const bool operator == (Vector const &v2) const;
    
    /// Checks for inequality of two vectors
    const bool operator != (Vector const &v2) const;
  };

}

#endif
