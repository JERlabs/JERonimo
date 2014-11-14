#ifndef _POINT_H_
#define _POINT_H_

#include <ostream>

#include "Declarations.h"

namespace jer {

/** Cartesian coordinate pair with support for numeric operators
 * Addition, subtraction, multiplication, division, etc. work in ways which maintain type consistencies.
 * Supports implicit conversions to and from polar coordinate Vector's.
 */
template<typename T>
class Point {
  protected:
    X_t<T> X; ///< X coordinate
    Y_t<T> Y; ///< Y coordinate
  public:
    /// Construct a point from an X and Y value
    Point (const X_t<T>& x, const Y_t<T>& y): X(x), Y(y) {};
    
    /// Construct a point from another point, converting its parts if necessary
    template<typename U>
    Point (Point<U> const& p2): X(T(U(p2.x()))), Y(T(U(p2.y()))) {};
    
    /// Construct a point from a Vector
    Point (const Vector &v);
    
    /// Construct a point with value (0,0)
    Point (): X(), Y() {};
    
    /// Return the X coordinate as an X_t
    const X_t<T>& x() const {
      return X;
    };
    
    /// Return a mutable reference to the X-coordinate as an X_t
    X_t<T>& x() {
        return X;
    };
    
    /// Set the X coordinate to x, returns reference to self for chain function calls
    Point<T>& x(const X_t<T> & x) {
        X=x;
        return *this;
    };
    
    /// For override use in velocity \deprecated
    virtual void x(const double & x) {
        X=x;
    };
    
    /// Return the Y-coordinate as a Y_t
    const Y_t<T> &y() const {
      return Y;
    };
    
    /// Returns a mutable reference to the Y-coordinate as a Y_t
    Y_t<T> &y() {
        return Y;
    };
    
    /// Set the Y coordinate, returns reference to self for chain function calls
    Point<T>& y(const Y_t<T>& y) {
        Y=y; 
        return *this;
    };
    
    /// For override use in velocity \deprecated
    virtual void y(const double& y) {
        Y=y;
    };
    
    /// Assigns coordinate pair from p2
    Point<T>& operator = (Point<T> const& p2);
    
    /// Adds x and y coordinates of p2 to x and y coordinates of <code>this</code> respectively
    Point<T>& operator += (Point<T> const& p2);
    
    /// Adds argument to the x coordinate of <code>this</code>
    Point<T>& operator += (const X_t<T>& x);
    
    /// Adds argument to the y coordinate of <code>this</code>
    Point<T>& operator += (const Y_t<T>& y);
    
    /// Subtracts x and y coordinates of p2 from x and y coordinates of <code>this</code> respectively
    Point<T>& operator -= (Point<T> const& p2);
    
    /// Subtracts argument from the x coordinate of <code>this</code>
    Point<T>& operator -= (const X_t<T>& x);
    
    /// Subtracts argument from the x coordinate of <code>this</code>
    Point<T>& operator -= (const Y_t<T>& y);
    
    /// Multiplies both X and Y coordinate by scale
    Point<T>& operator *= (const T& scale);
    
    /// Divides both X and Y coordinate by scale
    Point<T>& operator /= (const T& scale);
    
    /// Evaluates equality of X and Y coordinates of <code>this</code> and <code>p</code>
    const bool operator == (const Point<T> &p) const {
      return X == p.x() && Y == p.y();
    };
    
    /// Evaluates inequality of X and Y coordinates of <code>this</code> and <code>p</code>
    const bool operator != (const Point<T> &p) const {
      return !(*this == p);
    };
};

template<typename T>
inline Point<T>& Point<T>::operator = (Point<T> const &p2) {
    x(p2.x());
    y(p2.y());
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator += (Point<T> const &p2) {
    return (*this += p2.x()) += p2.y();
}

template<typename T>
inline Point<T>& Point<T>::operator += (X_t<T> const &rhs) {
    x(x() + rhs);
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator += (Y_t<T> const &rhs) {
    y(y() + rhs);
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator -= (Point<T> const &p2) {
    return (*this -= p2.x()) -= p2.y();
}

template<typename T>
inline Point<T>& Point<T>::operator -= (X_t<T> const &rhs) {
    x(x() - rhs);
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator -= (Y_t<T> const &rhs) {
    y(y() - rhs);
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator *= (const T& scale) {
    x(x()*scale);
    y(y()*scale);
    return *this;
}

template<typename T>
inline Point<T>& Point<T>::operator /= (const T &scale) {
    x(x()/(scale == 0? 1:scale));
    y(y()/(scale == 0? 1:scale));
    return *this;
}

template<typename T>
using Dimensions = Point<T>;   ///< Alias for Point for use in conceptual disambiguity

/** Returns a Point with X and Y coordinates formed from the sum of the X and Y coordinates of the operands
 * \see Point::operator+=
 */
template<typename T>
inline const Point<T> operator+ (const Point<T>& lhs, const Point<T>& rhs) {
  return Point<T>(lhs) += rhs;
};

/** Returns a Point with X and Y coordinates formed from the sum of the X coordinates of the operands, and the Y cooridnate of the left hand operand
 * \see Point::operator+=
 */
template<typename T>
inline const Point<T> operator+ (const Point<T>& lhs, const X_t<T>& rhs) {
  return Point<T>(lhs) += rhs;
};

/** Returns a Point with X and Y coordinates formed from the sum of the Y coordinates of the operands, and the X cooridnate of the left hand operand
 * \see Point::operator+=
 */
template<typename T>
inline const Point<T> operator+ (const Point<T>& lhs, const Y_t<T>& rhs) {
  return Point<T>(lhs) += rhs;
};

/** Returns a Point with X and Y coordinates formed from the sum of the X coordinates of the operands, and the Y cooridnate of the right hand operand
 * \see Point::operator+=
 */
template<typename T>
inline const Point<T> operator+ (const X_t<T>& lhs, const Point<T>& rhs) {
  return rhs+lhs;
};

/** Returns a Point with X and Y coordinates formed from the sum of the Y coordinates of the operands, and the X cooridnate of the right hand operand
 * \see Point::operator+=
 */
template<typename T>
inline const Point<T> operator+ (const Y_t<T>& lhs, const Point<T>& rhs) {
  return rhs+lhs;
};

/** Returns a Point with X and Y coordinates formed from the difference of the X and Y coordinates of the operands
 * \see Point::operator-=
 */
template<typename T>
inline const Point<T> operator- (const Point<T>& lhs, const Point<T>& rhs) {
  return Point<T>(lhs) -= rhs;
};

/** Returns a Point with X and Y coordinates formed from the difference of the X coordinates of the operands, and the Y cooridnate of the left hand operand
 * \see Point::operator-=
 */
template<typename T>
inline const Point<T> operator- (const Point<T>& lhs, const X_t<T>& rhs) {
  return Point<T>(lhs) -= rhs;
};

/** Returns a Point with X and Y coordinates formed from the difference of the Y coordinates of the operands, and the X cooridnate of the left hand operand
 * \see Point::operator-=
 */
template<typename T>
inline const Point<T> operator- (const Point<T>& lhs, const Y_t<T>& rhs) {
  return Point<T>(lhs) -= rhs;
};

/** Returns a Point with X and Y coordinates formed from the difference of the X coordinates of the operands, and the Y cooridnate of the right hand operand
 * \see Point::operator-=
 */
template<typename T>
inline const Point<T> operator- (const X_t<T>& lhs, const Point<T>& rhs) {
  return -(rhs-lhs);
};

/** Returns a Point with X and Y coordinates formed from the difference of the Y coordinates of the operands, and the X cooridnate of the right hand operand
 * \see Point::operator-=
 */
template<typename T>
inline const Point<T> operator- (const Y_t<T>& lhs, const Point<T>& rhs) {
  return -(rhs-lhs);
};

/** Returns a Point with the X and Y coordinates formed from scaling the X and Y coordinates of the left hand operand by the right hand operand
 * \see Point::operator*=
 */
template<typename T>
inline const Point<T> operator* (const Point<T> &lhs, const T& scale) {
  return Point<T>(lhs) *= scale;
};

/** Returns a Point with the X and Y coordinates formed from scaling the X and Y coordinates of the right hand operand by the left hand operand
 * \see Point::operator*=
 */
template<typename T>
inline const Point<T> operator* (const T& lhs, const Point<T> &rhs) {
  return rhs * lhs;
};

/** Returns a Point with the X and Y coordinates formed from inversely scaling the X and Y coordinates of the left hand operand by right hand operand
 * \see Point::operator/=
 */
template<typename T>
inline const Point<T> operator/ (const Point<T> &lhs, const T &scale) {
  return Point<T>(lhs.x()/scale, lhs.y()/scale);
};

/// Returns a Point with the X and Y coordinates fromed from the opposite of X and Y coordinates of the operand
template<typename T>
inline const Point<T> operator- (const Point<T> &lhs) {
  return Point<T>(-lhs.x(), -lhs.y());
}

/// Returns the hypotenuse of a right triangle formed from legs with measures of the X and Y coordinates of <code>p</code>
template<typename T>
inline const T pythagoras(const Point<T>& p) {
  return pythagoras(p.x(), p.y());
}

/// Returns the angle (in Radians) between the hypotenuse and adjacent leg of a right triangle formed from legs with measures of the X and Y coordinates of <code>p</code>
template<typename T>
inline const Radians getTheta(const Point<T> &p) {
  return getTheta(p.x(), p.y());
}

/// Outputs the X and Y coordinates of <code>p</code> to the stream <code>os</code> in the format "(x, y)"
template<typename T>
inline std::ostream &operator<< (std::ostream &os, Point<T> p) {
    return os<<"("<<p.x()<<", "<<p.y()<<")";
}
  
}

#endif