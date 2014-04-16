#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Point.h"

namespace jer
{

template<typename T>
class Vector {
  protected:
    /// Magnitude of the vector
    Mag_t<T> Mag;
    
    /// Angle of the vector
    Radians<T> Theta;
    
  public:
    /// Create a vector from a magnitude and angle
    Vector(const Mag_t<T> &mag, const Radians<T> &theta): Mag(mag), Theta(theta) {};
    
    /// Create a vector from another vector
    Vector(Vector<T> const &v2): Mag(v2.Mag), Theta(v2.Theta) {};
    
    /// Create a vector from a Point
    Vector(const Point<T> &p2): Mag(pythagoras(p2)), Theta(getTheta(p2)) {};
    
    /// Create a vector with default values
    Vector(): Mag(1), Theta() {};
    
/*    operator const Point<T>() const {return Point<T>(getX(mag(), theta()), getY(mag(), theta()));};
    operator const Point<T>() {return Point<T>(getX(mag(), theta()), getY(mag(), theta()));};
 */
    
  public:
    /// Returns the magnitude of the vector
    const Mag_t<T> &mag() const {
      return Mag;
    };
    
    /// Sets the magnitude of the vector to m
    Vector<T>& mag(const Mag_t<T> &m);
    virtual void mag(const double &m) {Mag = Mag_t<double>(m);};
    
    /// Returns the angle of the vector
    const Radians<T> &theta() const {
      return Theta;
    };
    
    /// Sets the angle of the vector to t, returns new angle
    Vector<T> &theta(const Radians<T> &t);
    virtual void theta(const double &t) {Theta = Radians<double>(t);}; ///< IMPORTANT: t must be in radians!
    void theta(const Degrees<double> &d) {theta(double(d));};  ///< Okay if you call this in Degrees I've saved your ass
    
  public:
    /// Sets the magnitude and angle of the vector to that of another
    Vector<T>& operator = (Vector<T> const& v2);
    
    /// Adds the vector to a point
    Vector<T>& operator += (Point<T> const& p2);
    
    /// Subtracts a point from the vector
    Vector<T>& operator -= (Point<T> const& p2);
    
    /// Scales the vector by scale
    Vector<T>& operator *= (const T &scale);
    
    /// Scales the vector by scale
    Vector<T>& operator /= (const T &scale);
    
    /// Checks for equality of two vectors
    const bool operator == (Vector<T> const &v2) const {
      return Mag == v2.mag() && Theta == v2.theta();
    };
    
    /// Checks for inequality of two vectors
    const bool operator != (Vector<T> const &v2) const {
      return !(*this == v2);
    };
  };
  
  template<typename T>
  inline Vector<T>& Vector<T>::mag(const Mag_t<T> &m) {
      Mag = m;
      return *this;
  }
    
  template<typename T>
  inline Vector<T>& Vector<T>::theta(const Radians<T> &t) {
      Theta = t;
      return *this;
  }
  
  template<typename T>
  inline Vector<T>& Vector<T>::operator= (Vector<T> const &v2) {
      Mag = v2.mag();
      Theta = v2.theta();
      return *this;
  }
  
  template<typename T>
  inline Vector<T>& Vector<T>::operator+= (Point<T> const &p2) {
      const Point<T> tmp(*this);
      Mag = pythagoras(p2.x() + tmp.x(), p2.y() + tmp.y());
      Theta = getTheta(p2.x() + tmp.x(), p2.y() + tmp.y());
      return *this;
  }
  
  template<typename T>
  inline Vector<T>& Vector<T>::operator-= (Point<T> const &p2) {
      const Point<T> tmp(*this);
      Mag = pythagoras(tmp.x() - p2.x(), tmp.y() - p2.y());
      Theta = getTheta(tmp.x() - p2.x(), tmp.y() - p2.y());
      return *this;
  }
  
  template<typename T>
  inline Vector<T>& Vector<T>::operator*= (const T &scale) {
      Mag *= scale;
      return *this;
  }
  
  template<typename T>
  inline Vector<T>& Vector<T>::operator/= (const T &scale) {
      Mag /= scale;
      return *this;
  }
  
  
  template<typename T>
  inline const Vector<T>& operator * (const Vector<T>& lhs, const T &rhs) {
    return Vector<T>(lhs) *= rhs;
  }
  
  template<typename T>
  inline const Vector<T>& operator * (const T &lhs, const Vector<T>& rhs) {
    return rhs * lhs;
  }
  
  template<typename T>
  inline const Vector<T>& operator / (const Vector<T>& lhs, const T &rhs) {
    return Vector<T>(lhs) /= rhs;
  }
  
  template<typename T>
  inline const X_t<T> getX(const Vector<T>& v) {
    return v.mag() * cos(v.theta());
  }
  
  template<typename T>
  inline const Y_t<T> getY(const Vector<T>& v) {
    return v.mag() * sin(v.theta());
  }

  
  template<typename T>
  inline Point<T>::Point(Vector<T> const &v): X(getX(v)), Y(getY(v)) {
  }
  
}

#endif
