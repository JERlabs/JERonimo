#ifndef _POINT_H_
#define _POINT_H_

#include "Space2D.h"

namespace Space2D {

class Point {
  protected:
    long double X; ///< X coordinate
    long double Y; ///< Y coordinate
  public:
    /// Construct a point from 2 long doubles
    Point (long double const& x, long double const& y);
    
    /// Construct a point from another point
    Point (Point const& p2);
    
    /// Construct a point from a vector
    Point (Vector const& v2);
    
    /// Construct a point with value (0,0)
    Point ();
    
    /// Return the X coordinate as a long double
    const long double x() const;
    
    /// Set the X coordinate, returns the new X value
    const long double x(long double const& x);
    
    /// Return the Y coordinate as a long double
    const long double y() const;
    
    /// Set the Y coordinate, returns the new Y value
    const long double y(long double const& y);
    
    /// Add two points together, result it (x1+x2,y1+y2);
    Point const operator + (Point const& p2) const;
    
    /// Subtract two points, result is (x1-x2,y1-y2)
    Point const operator - (Point const& p2) const;
    
    /// Return a point representing this point under a size transformation with magnitude scale
    Point const operator * (long double const& scale) const;
    
    /// Return a point representing this point under a size transformation with magnitude 1/scale
    Point const operator / (long double const& scale) const;
    
    /// Set x,y of this point to equal x,y of another point
    Point& operator = (Point const& p2);
    
    /// Set x to x+p2.x(), set y to y+p2.y()
    Point& operator += (Point const& p2);
    
    /// Set x to x-p2.x(), set y to y-p2.y()
    Point& operator -= (Point const& p2);
    
    /// Apply a size transformation of magnitude scale
    Point& operator *= (long double const& scale);
    
    /// Apply a size transformation of magnitude 1/scale
    Point& operator /= (long double const& scale);
    
    /// Check equality of values between this point and another point
    const bool operator == (Point const& p2) const;
    
    /// Check inequality of values between this point and another point
    const bool operator != (Point const& p2) const;
};

}

#endif