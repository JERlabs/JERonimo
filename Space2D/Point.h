#ifndef _POINT_H_
#define _POINT_H_

#include "Declarations.h"

namespace jer {

template<typename T>
class Point {
  protected:
    X_t<T> X; ///< X coordinate
    Y_t<T> Y; ///< Y coordinate
  public:
    /// Construct a point from an X and Y value
    Point (const X_t<T>& x, const Y_t<T>& y): X(x), Y(y) {};
    
    /// Construct a point from another point
    Point (Point<T> const& p2): X(p2.X), Y(p2.Y) {};
    
    /// Construct a point with value (0,0)
    Point (): X(), Y() {};
    
    /// Return the X coordinate as an X_t
    const X_t<T>& x() const {
      return X;
    };
    
    X_t<T>& x() {
      return X;
    }
    
    /// Set the X coordinate, returns *this
    Point<T>& x(const X_t<T> & x) {
        X=x; 
        return *this;
    };
    
    /// Return the Y coordinate as a long double
    const Y_t<T> &y() const {
      return Y;
    };
    
    Y_t<T> &y() {
      return Y;
    }
    
    /// Set the Y coordinate, returns *this
    Point<T>& y(const Y_t<T>& y) {
        Y=y; 
        return *this;

    };
    
    /// Set x,y of this point to equal x,y of another point
    Point<T>& operator = (Point<T> const& p2);
    
    /// Set x to x+p2.x(), set y to y+p2.y()
    Point<T>& operator += (Point<T> const& p2);
    Point<T>& operator += (const X_t<T>& x);
    Point<T>& operator += (const Y_t<T>& y);
    
    /// Set x to x-p2.x(), set y to y-p2.y()
    Point<T>& operator -= (Point<T> const& p2);
    Point<T>& operator -= (const X_t<T>& x);
    Point<T>& operator -= (const Y_t<T>& y);
    
    /// Apply a size transformation of magnitude scale
    Point<T>& operator *= (const T& scale);
    
    
    /// Apply a size transformation of magnitude 1/scale
    Point<T>& operator /= (const T& scale);
    
    /// Checks for equality in both X and Y.
    const bool operator == (const Point<T> &p) const {
      return X == p.x() && Y == p.y();
    };
    
    /// Returns opposite of ==.
    const bool operator != (const Point<T> &p) const {
      return !(*this == p);
    };
};

template<typename T>
inline Point<T>& Point<T>::operator = (Point<T> const &p2) {
    X = p2.x();
    Y = p2.y();
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator += (Point<T> const &p2) {
    X += p2.x();
    Y += p2.y();
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator += (X_t<T> const &x) {
    X += x;
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator += (Y_t<T> const &y) {
    Y += y;
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator -= (Point<T> const &p2) {
    X -= p2.x();
    Y -= p2.y();
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator -= (X_t<T> const &x) {
    X -= x;
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator -= (Y_t<T> const &y) {
    Y -= y;
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator *= (const T& scale) {
    X *= scale;
    Y *= scale;
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator /= (const T &scale) {
    X /= scale == 0? 1:scale;
    Y /= scale == 0? 1:scale;
    return *this;
}

template<typename T>
using Dimensions = Point<T>;   ///< Same as point, but different name. oooooohhhhh.

/// Point+Point addition.
template<typename T>
inline const Point<T> operator+ (const Point<T>& lhs, const Point<T>& rhs) {
  return Point<T>(lhs) += rhs;
};

/// Point+X addition.
template<typename T>
inline const Point<T> operator+ (const Point<T>& lhs, const X_t<T>& rhs) {
  return Point<T>(lhs) += rhs;
};

/// Point+Y addition
template<typename T>
inline const Point<T> operator+ (const Point<T>& lhs, const Y_t<T>& rhs) {
  return Point<T>(lhs) += rhs;
};

/// X+Point addition
template<typename T>
inline const Point<T> operator+ (const X_t<T>& lhs, const Point<T>& rhs) {
  return rhs+lhs;
};

/// Y+Point addition
template<typename T>
inline const Point<T> operator+ (const Y_t<T>& lhs, const Point<T>& rhs) {
  return rhs+lhs;
};

/// Point-Point subtraction
template<typename T>
inline const Point<T> operator- (const Point<T>& lhs, const Point<T>& rhs) {
  return Point<T>(lhs) -= rhs;
};

/// Point-X addition.
template<typename T>
inline const Point<T> operator- (const Point<T>& lhs, const X_t<T>& rhs) {
  return Point<T>(lhs) -= rhs;
};

/// Point-Y addition
template<typename T>
inline const Point<T> operator- (const Point<T>& lhs, const Y_t<T>& rhs) {
  return Point<T>(lhs) -= rhs;
};

/// X-Point addition
template<typename T>
inline const Point<T> operator- (const X_t<T>& lhs, const Point<T>& rhs) {
  return rhs+lhs;
};

/// Y-Point addition
template<typename T>
inline const Point<T> operator- (const Y_t<T>& lhs, const Point<T>& rhs) {
  return lhs+rhs;
};

/// Point*scale multiplication
template<typename T>
inline const Point<T> operator* (const Point<T> &lhs, const T& scale) {
  return Point<T>(lhs) *= scale;
};

/// scale*Point multiplication
template<typename T>
inline const Point<T> operator* (const T& lhs, const Point<T> &rhs) {
  return rhs * lhs;
};

/// Point/scale division
template<typename T>
inline const Point<T> operator/ (const Point<T> &lhs, const T &scale) {
  return Point<T>(lhs)/scale;
};

template<typename T>
inline const Point<T> operator- (const Point<T> &lhs) {
  return Point<T>(-lhs.x(), -lhs.y());
}

/// Returns the square root of p.x() squared + p.y() squared.
template<typename T>
inline const T pythagoras(const Point<T>& p) {
  return pythagoras(p.x(), p.y());
}

template<typename T>
inline const Radians<T> getTheta(const Point<T> &p) {
  return getTheta(p.x(), p.y());
}
  
}

#endif