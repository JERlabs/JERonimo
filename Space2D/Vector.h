#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Point.h"

namespace jer
{

/** Polar coordinates with support for numeric operators
 * Addition, subtraction, multiplication, division, etc. work in ways which maintian type consistencies
 * Supports implicit conversions to and from cartesian coordinate Point's
 */
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
    
    /** Create a vector with default values
     * Magnitude of 1 to avoid division by 0 issues that could arise
     */ 
    Vector(): Mag(1), Theta() {};
    
//    operator const Point<T>() const {return Point<T>(getX(mag(), theta()), getY(mag(), theta()));};
//    operator const Point<T>() {return Point<T>(getX(mag(), theta()), getY(mag(), theta()));};
    
  public:
    /// Returns the magnitude of the Vector
    const Mag_t<double> &mag() const {
      return Mag;
    };
    
    /// Returns a mutable reference to the magnitude of the Vector
    Mag_t<double> &mag() {
      return Mag;
    };
    
    /** Sets the magnitude of the Vector to m
     * \return reference to self for chain function calls
     */
    Vector& mag(const Mag_t<double> &m);
    
    /// Magnitude set function for override purposes in Velocity \deprecated
    virtual void mag(const double &m) {Mag = Mag_t<double>(m);};
    
    /// Returns the angle of the Vector
    const Radians &theta() const {
      return Theta;
    };
    
    /// Returns a mutable reference to the angle of the Vector
    Radians &theta() {
      return Theta;
    };
    
    /// Sets the angle of the vector to t
    Vector &theta(const Radians &t);
    
    
    virtual void theta(const double &t) {Theta = Radians(t);}; ///< IMPORTANT: t must be in radians! \deprecated
    void theta(const Degrees &d) {theta(Radians(d));};  ///< Okay if you call this in Degrees I've saved your ass \deprecated
    
  public:
    /// Assigns the magnitude and angle of the Vector to those of another
    Vector& operator = (Vector const& v2);
    
    /** Uses Vector addition to add <code>p2</code> to the Vector
     * \see Point::operator+=
     */
	template<typename T>
    Vector& operator += (Point<T> const& p2);
    
    /** Uses Vector subtraction to subtract <code>p2</code> from the Vector
     * \see Point::operator-=
     */
	template<typename T>
    Vector& operator -= (Point<T> const& p2);
    
    /** Scales the magnitude of the Vector by scale
     * \see Point::operator*=
     */
    Vector& operator *= (const double &scale);
    
    /** Inversely scales the magnitude of the Vector by scale
     * \see Point::operator/=
     */
    Vector& operator /= (const double &scale);
    
    /// Evaluates equality of the magnitude and angle of the the operand Vectors
    const bool operator == (Vector const &v2) const {
      return Mag == v2.mag() && Theta == v2.theta();
    };
    
    /// Evalutates inequality of the magnitude and angle of the operand Vectors
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
  
  /** Returns a Vector who's magnitude is scaled by the right hand operand
   * \see Vector::operator*=
   */
  inline const Vector& operator * (const Vector& lhs, const double &rhs) {
    return Vector(lhs) *= rhs;
  }
  
  /** Returns a Vector who's magnitude is scaled by the left hand operand
   * \see Vector::operator*=
   */
  inline const Vector& operator * (const double &lhs, const Vector& rhs) {
    return rhs * lhs;
  }
  
  /** Returns a Vector who's magnitude is inversely scaled by the right hand operand
   * \see Vector::operator/=
   */
  inline const Vector& operator / (const Vector& lhs, const double &rhs) {
    return Vector(lhs) /= rhs;
  }
  
  /// Returns X component of a Vector
  inline const X_t<double> getX(const Vector& v) {
    return v.mag() * cos(v.theta());
  }
  
  /// Returns Y component of a Vector
  inline const Y_t<double> getY(const Vector& v) {
    return v.mag() * sin(v.theta());
  }

  template<typename T>
  inline Point<T>::Point(Vector const &v): X(getX(v)), Y(getY(v)) {
  }
  
}

#endif
