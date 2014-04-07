#ifndef _POINT_H_
#define _POINT_H_

#include "Declarations.h"

namespace jer {

class Point {
  protected:
    X_t X; ///< X coordinate
    Y_t Y; ///< Y coordinate
  public:
    /// Construct a point from an X and Y value
    Point (const X_t& x, const Y_t& y): X(x), Y(y) {};
    
    /// Construct a point from another point
    Point (Point const& p2): X(p2.X), Y(p2.Y) {};
    
    /// Construct a point from a vector
    Point(Vector const &v2); //: X(getX(v2.mag(), v2.theta())), Y(getY(v2.mag(), v2.theta())) {};
    
    /// Construct a point with value (0,0)
    Point (): X(), Y() {};
    
    /// Return the X coordinate as an X_t
    const X_t& x() const {
      return X;
    };
    
    X_t& x() {
      return X;
    }
    
    /// Set the X coordinate, returns *this
    virtual Point& x(const X_t & x);
    
    /// Return the Y coordinate as a long double
    const Y_t &y() const {
      return Y;
    };
    
    Y_t &y() {
      return Y;
    }
    
    /// Set the Y coordinate, returns *this
    virtual Point& y(const Y_t& y);
    
    /// Set x,y of this point to equal x,y of another point
    Point& operator = (Point const& p2);
    
    /// Set x to x+p2.x(), set y to y+p2.y()
    Point& operator += (Point const& p2);
    Point& operator += (const X_t& x);
    Point& operator += (const Y_t& y);
    
    /// Set x to x-p2.x(), set y to y-p2.y()
    Point& operator -= (Point const& p2);
    Point& operator -= (const X_t& x);
    Point& operator -= (const Y_t& y);
    
    /// Apply a size transformation of magnitude scale
    Point& operator *= (const PIXEL_TYPE& scale);
    
    
    /// Apply a size transformation of magnitude 1/scale
    Point& operator /= (const PIXEL_TYPE& scale);
    
    /// Checks for equality in both X and Y.
    const bool operator == (const Point &p) const {
      return X == p.x() && Y == p.y();
    };
    
    /// Returns opposite of ==.
    const bool operator != (const Point &p) const {
      return !(*this == p);
    };
};

typedef Point Dimensions;   ///< Same as point, but different name. oooooohhhhh.

/// Point+Point addition.
inline const Point operator+ (const Point& lhs, const Point& rhs) {
  return Point(lhs) += rhs;
};

/// Point+X addition.
inline const Point operator+ (const Point& lhs, const X_t& rhs) {
  return Point(lhs) += rhs;
};

/// Point+Y addition
inline const Point operator+ (const Point& lhs, const Y_t& rhs) {
  return Point(lhs) += rhs;
};

/// X+Point addition
inline const Point operator+ (const X_t& lhs, const Point& rhs) {
  return rhs+lhs;
};

/// Y+Point addition
inline const Point operator+ (const Y_t& lhs, const Point& rhs) {
  return rhs+lhs;
};

/// Point-Point subtraction
inline const Point operator- (const Point& lhs, const Point& rhs) {
  return Point(lhs) -= rhs;
};

/// Point-X addition.
inline const Point operator- (const Point& lhs, const X_t& rhs) {
  return Point(lhs) -= rhs;
};

/// Point-Y addition
inline const Point operator- (const Point& lhs, const Y_t& rhs) {
  return Point(lhs) -= rhs;
};

/// X-Point addition
inline const Point operator- (const X_t& lhs, const Point& rhs) {
  return rhs+lhs;
};

/// Y-Point addition
inline const Point operator- (const Y_t& lhs, const Point& rhs) {
  return lhs+rhs;
};

/// Point*scale multiplication
inline const Point operator* (const Point &lhs, const PIXEL_TYPE& scale) {
  return Point(lhs) *= scale;
};

/// scale*Point multiplication
inline const Point operator* (const PIXEL_TYPE& lhs, const Point &rhs) {
  return rhs * lhs;
};

/// Point/scale division
inline const Point operator/ (const Point &lhs, const PIXEL_TYPE &scale) {
  return Point(lhs)/scale;
};

inline const Point operator- (const Point &lhs) {
  return Point(-lhs.x(), -lhs.y());
}

/// Returns the square root of p.x() squared + p.y() squared.
inline const PIXEL_TYPE pythagoras(const Point& p) {
  return pythagoras(p.x(), p.y());
}


inline const Radians getTheta(const Point &p) {
  return getTheta(p.x(), p.y());
}
  
}

#endif