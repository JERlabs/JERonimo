#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Point.h"

namespace jer
{

class Vector {
  protected:
    /// Magnitude of the vector
    Mag_t<double> Mag;
    
    /// Angle of the vector
    Radians Theta;
    
  public:
    /// Create a vector from a magnitude and angle
    Vector(const Mag_t<double> &mag, const Radians &theta): Mag(mag), Theta(theta) {};
    
    /// Create a vector from another vector
    Vector(Vector const &v2): Mag(v2.Mag), Theta(v2.Theta) {};
    
    /// Create a vector from a Point
	template<typename T>
    Vector(const Point<T> &p2): Mag(pythagoras(p2)), Theta(getTheta(p2)) {};
    
    /// Create a vector with default values
    Vector(): Mag(1), Theta() {};
    
//    operator const Point<T>() const {return Point<T>(getX(mag(), theta()), getY(mag(), theta()));};
//    operator const Point<T>() {return Point<T>(getX(mag(), theta()), getY(mag(), theta()));};
    
  public:
    /// Returns the magnitude of the vector
    const Mag_t<double> &mag() const {
      return Mag;
    };
    
    Mag_t<double> &mag() {
      return Mag;
    };
    
    /// Sets the magnitude of the vector to m
    Vector& mag(const Mag_t<double> &m);
    virtual void mag(const double &m) {Mag = Mag_t<double>(m);};
    
    /// Returns the angle of the vector
    const Radians &theta() const {
      return Theta;
    };
    
    Radians &theta() {
      return Theta;
    };
    
    /// Sets the angle of the vector to t, returns new angle
    Vector &theta(const Radians &t);
    virtual void theta(const double &t) {Theta = Radians(t);}; ///< IMPORTANT: t must be in radians!
    void theta(const Degrees &d) {theta(Radians(d));};  ///< Okay if you call this in Degrees I've saved your ass
    
  public:
    /// Sets the magnitude and angle of the vector to that of another
    Vector& operator = (Vector const& v2);
    
    /// Adds the vector to a point
	template<typename T>
    Vector& operator += (Point<T> const& p2);
    
    /// Subtracts a point from the vector
	template<typename T>
    Vector& operator -= (Point<T> const& p2);
    
    /// Scales the vector by scale
    Vector& operator *= (const double &scale);
    
    /// Scales the vector by scale
    Vector& operator /= (const double &scale);
    
    /// Checks for equality of two vectors
    const bool operator == (Vector const &v2) const {
      return Mag == v2.mag() && Theta == v2.theta();
    };
    
    /// Checks for inequality of two vectors
    const bool operator != (Vector const &v2) const {
      return !(*this == v2);
    };
  };
  
  inline Vector& Vector::mag(const Mag_t<double> &m) {
      Mag = m;
      return *this;
  }
    
  inline Vector	& Vector::theta(const Radians &t) {
      Theta = t;
      return *this;
  }
  
  inline Vector& Vector::operator= (Vector const &v2) {
      Mag = v2.mag();
      Theta = v2.theta();
      return *this;
  }
  
  template<typename T>
  inline Vector& Vector::operator+= (Point<T> const &p2) {
      const Point<T> tmp(*this);
      Mag = pythagoras<T>(p2.x() + tmp.x(), p2.y() + tmp.y());
      Theta = getTheta<T>(p2.x() + tmp.x(), p2.y() + tmp.y());
      return *this;
  }
  
  template<typename T>
  inline Vector& Vector::operator-= (Point<T> const &p2) {
      const Point<T> tmp(*this);
      Mag = pythagoras<T>(tmp.x() - p2.x(), tmp.y() - p2.y());
      Theta = getTheta<T>(tmp.x() - p2.x(), tmp.y() - p2.y());
      return *this;
  }

  
  inline Vector& Vector::operator*= (const double &scale) {
      Mag *= scale;
      return *this;
  }
  
  inline Vector& Vector::operator/= (const double &scale) {
      Mag /= scale;
      return *this;
  }
  
  inline const Vector& operator * (const Vector& lhs, const double &rhs) {
    return Vector(lhs) *= rhs;
  }
  
  inline const Vector& operator * (const double &lhs, const Vector& rhs) {
    return rhs * lhs;
  }
  
  inline const Vector& operator / (const Vector& lhs, const double &rhs) {
    return Vector(lhs) /= rhs;
  }
  
  inline const X_t<double> getX(const Vector& v) {
    return v.mag() * cos(v.theta());
  }
  
  inline const Y_t<double> getY(const Vector& v) {
    return v.mag() * sin(v.theta());
  }

  template<typename T>
  inline Point<T>::Point(Vector const &v): X(getX(v)), Y(getY(v)) {
  }
  
}

#endif
