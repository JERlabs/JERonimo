#ifndef _SPACE_2D_H_
#define _SPACE_2D_H_

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define M_PI		3.14159265358979323846
typedef double PIXEL_TYPE;

namespace jer {
  /*space containing code related to 2D space algorithm 
  * such as coordinate plane geometry, vector math, 
  * and certain physics calculations 
  * The template types should be a numerical type with at least support for 
  * binary operator+, binary operator-, binary operator*, operator/, operator=, and operator==
  */
  
  template<typename T> class Vector;
  template<typename T> class Point;
  
  
  template<typename T>
  class Scalar {
  public:
    typedef T &T_REF;
    
  protected:
    T val;
    
  public:
    operator T&() {return val;};
    operator const T&() const {return val;};
    Scalar(): val(T(0.0)) {};
    Scalar(const T& v): val(v) {};
    Scalar(const Scalar &other): val(other.val) {};
  };
  
  template<typename T>
  class X_t: public Scalar<T> {
  public:
    X_t(): Scalar<T>() {};
    X_t(const T& x): Scalar<T>(x) {};
    X_t(const Scalar<T> &other): Scalar<T>(other) {};
  };
  
  template<typename T>
  class Y_t: public Scalar<T> {
  public:
      Y_t(): Scalar<T>() {};
      Y_t(const T& y): Scalar<T>(y) {};
      Y_t(const Scalar<T> &other): Scalar<T>(other) {};
  };
  
  template<typename T>
  class Mag_t: public Scalar<T> {
  public:
    Mag_t(): Scalar<T>() {};
    explicit Mag_t(const T& m): Scalar<T>(m) {};
    Mag_t(const Scalar<T> &other): Scalar<T>(other) {};
  };
  
  template<typename T>
  inline const Mag_t<T> operator+ (const Mag_t<T>& lhs, const Mag_t<T>& rhs) {
      return Mag_t<T>(T(lhs)+T(rhs));
  }
  
  template<typename T>
  inline const Mag_t<T> operator- (const Mag_t<T>& lhs, const Mag_t<T>& rhs) {
      return Mag_t<T>(T(lhs)-T(rhs));
  }
  
  template<typename T>
  inline const Mag_t<T> operator* (const Mag_t<T>& lhs, const T& rhs) {
      return Mag_t<T>(T(lhs)*T(rhs));
  }
  
  template<typename T>
  inline const Mag_t<T> operator/ (const Mag_t<T>& lhs, const T& rhs) {
      return Mag_t<T>(T(lhs)/T(rhs));
  }
  
  template<typename T>
  inline const T operator/ (const Mag_t<T> & lhs, const Mag_t<T> & rhs) {
      return T(T(lhs)/T(rhs));
  }  
  
  template<typename T>
  class Degrees: public Scalar<T> {
  public:
    Degrees(): Scalar<T>() {};
    explicit Degrees(const T& a=0): Scalar<T>(a) {};
    // not sure exactly why this is here, I'm removing it for now
    //Degrees(const Mag_t &other): Scalar(other) {};  
    Degrees(const Scalar<T> &other): Scalar<T>(other) {};
    
    static const Degrees<double> ANGLE_RIGHT;
    static const Degrees<double> ANGLE_UP;
    static const Degrees<double> ANGLE_LEFT;
    static const Degrees<double> ANGLE_DOWN;
  };
  
  template<typename T>
  inline const Degrees<T> operator+ (const Degrees<T>& lhs, const Degrees<T>& rhs) {
      return Degrees<T>(T(lhs)+T(rhs));
  }
  
  template<typename T>
  inline const Degrees<T> operator- (const Degrees<T>& lhs, const Degrees<T>& rhs) {
      return Degrees<T>(T(lhs)-T(rhs));
  }
  
  template<typename T>
  inline const Degrees<T> operator* (const Degrees<T>& lhs, const T& rhs) {
      return Degrees<T>(T(lhs)*T(rhs));
  }
  
  template<typename T>
  inline const Degrees<T> operator/ (const Degrees<T>& lhs, const T& rhs) {
      return Degrees<T>(T(lhs)/T(rhs));
  }
  
  template<typename T>
  inline const T operator/ (const Degrees<T> & lhs, const Degrees<T> & rhs) {
      return T(T(lhs)/T(rhs));
  }
  
  template<typename T>
  class Radians: public Scalar<T> {
  public:
    operator Degrees<T>&();
    operator const Degrees<T>&() const;
    Radians(): Scalar<T>() {};
    explicit Radians(const T &a): Scalar<T>(a) {};
    Radians(const Degrees<T> &other);
    Radians(const Scalar<T> &other): Scalar<T>(other) {};
  
    static const Radians<double> ANGLE_RIGHT;
    static const Radians<double> ANGLE_UP;
    static const Radians<double> ANGLE_LEFT;
    static const Radians<double> ANGLE_DOWN;
  };
  
  template<typename T>
  inline const Radians<T> operator+ (const Radians<T>& lhs, const Radians<T>& rhs) {
      return Radians<T>(T(lhs)+T(rhs));
  }
  
  template<typename T>
  inline const Radians<T> operator- (const Radians<T>& lhs, const Radians<T>& rhs) {
      return Radians<T>(T(lhs)-T(rhs));
  }
  
  template<typename T>
  inline const Radians<T> operator* (const Radians<T>& lhs, const T& rhs) {
      return Radians<T>(T(lhs)*T(rhs));
  }
  
  template<typename T>
  inline const Radians<T> operator/ (const Radians<T>& lhs, const T& rhs) {
      return Radians<T>(T(lhs)/T(rhs));
  }
  
  template<typename T>
  inline const T operator/ (const Radians<T> & lhs, const Radians<T> & rhs) {
      return T(T(lhs)/T(rhs));
  }
  
  const Radians<double> TAO(2*M_PI);  ///< Constant for TAO.

  /// Constant for 360 degrees. Created for type purity purposes. Doubts that it will be used.
  const Degrees<double> ANGLE_360(360.0);
  
  /// Converts from Degrees to Radians
  template<typename T>
  inline const Radians<T> DEGREES_TO_RAD(const T& d) {
    return (d/ANGLE_360)*TAO;
  }
  
  /// Converts from Radians to Degrees
  template<typename T>
  inline const Degrees<T> RAD_TO_DEGREES(const T& r) {
    return (r/TAO)*ANGLE_360;
  }
  
  /// Radians Degrees function needs to be defined after RAD_TO_DEGREES.
  template<typename T>
  inline Radians<T>::operator Degrees<T>&() {
    return RAD_TO_DEGREES(this->val);
  }
  
  template<typename T>
  inline Radians<T>::operator const Degrees<T>&() const {
    return RAD_TO_DEGREES(this->val);
  }
  
  /// Radians constructor needs to be defined after DEGREES_TO_RAD.
  template<typename T>
  inline Radians<T>::Radians(const Degrees<T> &other): Scalar<T>(DEGREES_TO_RAD(other.val)) {}
  
  
  /// Returns the square root of x squared + y squared.
  template<typename T>
  inline const Mag_t<T> pythagoras(const X_t<T> &x, const Y_t<T> &y) {
    return Mag_t<T>(sqrt(x*x + y*y));
  }
  
  /// Returns m times cos theta.
  template<typename T>
  inline const X_t<T> getX(const Mag_t<T>& m, const Radians<T>& theta) {
    return m * cos(theta);
  }
  
  /// Returns m times sin theta.
  template<typename T>
  inline const Y_t<T> getY(const Mag_t<T>& m, const Radians<T>& theta) {
    return m * sin(theta);
  }
  
  /// Returns arc tangent of y/x.
  template<typename T>
  inline const Radians<double> getTheta(const X_t<T>& x, const Y_t<T>& y) {
    if(x == 0.0) {
      if(y > 0.0)
        return Radians<double>(TAO/4.0);
      if(y < 0.0)
        return Radians<double>(3.0*TAO/4.0);
      
      return Radians<double>(9001.0);
    }
    
    if(x < 0.0)
      return Radians<double>(TAO/2.0 + atan(y/x));
    
    return Radians<double>(atan(y/x));
  }
}

#endif