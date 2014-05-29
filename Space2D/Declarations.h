#ifndef _SPACE_2D_H_
#define _SPACE_2D_H_

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define M_PI		3.14159265358979323846
typedef double PIXEL_TYPE;

namespace jer {
/** namespace containing code related to 2D space algorithm 
  * such as coordinate plane geometry, vector math, 
  * and certain physics calculations 
  * The template types should be a numerical type with at least support for 
  * binary operator+, binary operator-, binary operator*, operator/, operator=, and operator==
  */
  
  class Vector;   // forward declaration of vector
  template<typename T> class Point;  // forward declaration of Point, a template class (depending on the chosen units)
  
  
  template<typename T>
  class Scalar {
  /// Base class for Scalars (like X_t), which covers autoboxing of the value it holds of type T (hopefully some sort of numerical value)
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
  class Scalar<Scalar<T> > {
  /// Specialization of Scalar for squared Scalar values, also autoboxes to T, such that things like x*x + y*y are legal.
	protected:
	  Scalar<T> val;
	
	public:
	  operator T&() {return val;};
	  operator const T&() const {return val;};
	  Scalar(): val(Scalar<T>(0.0)) {};
	  Scalar(const T& v): val(Scalar<T>(v)) {};
	  Scalar(const Scalar<T> &other): val(other) {};
  };
  
  template<typename T>
  const Scalar<Scalar<T> > operator* (const Scalar<T>& lhs, const Scalar<T>& rhs) {
  /// Overload of the multiplication of two Scalar values resulting in a squared Scalar value (Scalar of Scalars)
	return lhs*T(rhs);
  }
  
  template<typename T>
  class X_t: public Scalar<T> {
  /// Scalar class representing X coordinate values
  public:
    X_t(): Scalar<T>() {};
    X_t(const T& x): Scalar<T>(x) {};
    X_t(const Scalar<T> &other): Scalar<T>(other) {};
  };
  
  template<typename T>
  class Y_t: public Scalar<T> {
  /// Scalar class representing Y coordinate values
  public:
      Y_t(): Scalar<T>() {};
      Y_t(const T& y): Scalar<T>(y) {};
      Y_t(const Scalar<T> &other): Scalar<T>(other) {};
  };
  
  template<typename T>
  class Mag_t: public Scalar<T> {
  /// Scalar class representing magnitudes or hypotenuses
  public:
    Mag_t(): Scalar<T>() {};
    explicit Mag_t(const T& m): Scalar<T>(m) {};  ///< Constructor requires that magnitudes be declared explicitly, so Vector parameters aren't swapped
    Mag_t(const Mag_t<T> &other): Scalar<T>(other) {};  ///< Copy Constructor
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
  inline const Mag_t<T> operator* (const Mag_t<T>& lhs, const T& rhs)
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
  
  class Degrees: public Scalar<double> {
  /// Class representing degree measures of angles stored, as doubles.
  public:
    Degrees(): Scalar<double>() {}; ///< Default Constructor
    explicit Degrees(const double& a=0.0): Scalar<double>(a) {};
	/// Explicit conversion from double so that code using angles doesn't have ambiguity as to whether it's a magnitude, angle in degrees, or angle in radians
    // not sure exactly why this is here, I'm removing it for now
    //Degrees(const Mag_t &other): Scalar(other) {};  
    explicit Degrees(const Scalar<double> &other): Scalar<double>(other) {};
	/// Conversion from Scalar is explicit so that scalar arithmetic doesn't get implicit-casted to Degrees
    
    static const Degrees ANGLE_RIGHT;  ///< Corresponds to an angle 0 quarter around the unit circle (0 degrees)
    static const Degrees ANGLE_UP;     ///< Corresponds to an angle 1 quarter around the unit circle (90 degrees)
    static const Degrees ANGLE_LEFT;   ///< Corresponds to an angle 2 quarters around the unit circle (180 degrees)
    static const Degrees ANGLE_DOWN;   ///< Corresponds to an angle 3 quarters around the unit circle (270 degrees)
  };
  
  inline const Degrees operator+ (const Degrees& lhs, const Degrees& rhs) {
      return Degrees(double(lhs)+double(rhs));
  }
  
  inline const Degrees operator- (const Degrees& lhs, const Degrees& rhs) {
      return Degrees(double(lhs)-double(rhs));
  }
  
  inline const Degrees operator* (const Degrees& lhs, const double& rhs) {
      return Degrees(double(lhs)*rhs);
  }
  
  inline const Degrees operator* (const double& lhs, const Degrees& rhs) {
	return rhs*lhs;
  }
  
  inline const Degrees operator/ (const Degrees& lhs, const double& rhs) {
      return Degrees(double(lhs)/rhs);
  }
  
  inline const double operator/ (const Degrees & lhs, const Degrees & rhs) {
      return double(double(lhs)/double(rhs));
  }
  
  class Radians: public Scalar<double> {
  /// Class representing radian measures of angles stored, as doubles.
  public:
    operator Degrees();  ///< Cast operator to Degrees. This allows implicit casts between Radians and Degrees, converting their values as well.
    operator const Degrees() const;   ///< Constant cast operator to Degrees. see <code>operator Degrees()</code>
    Radians(): Scalar<double>() {};	///< Default constructor
    explicit Radians(const double &a): Scalar<double>(a) {};
	/// Explicit conversion from double so that code using angles doesn't have ambiguity as to whether it's a magnitude, angle in degrees, or angle in radians
    Radians(const Degrees &other);  ///< Implicit conversion from Degrees. See <code>operator Degrees()</code>
    explicit Radians(const Scalar<double> &other): Scalar<double>(other) {};
	/// Conversion from Scalar is explicit so that scalar arithmetic doesn't get implicit-casted to Degrees
  
    static const Radians ANGLE_RIGHT;	///< Corresponds to an angle 0 quarter around the unit circle (0 radians)
    static const Radians ANGLE_UP;		///< Corresponds to an angle 1 quarter around the unit circle (pi/2 radians)
    static const Radians ANGLE_LEFT;	///< Corresponds to an angle 2 quarter around the unit circle (pi radians)
    static const Radians ANGLE_DOWN;    ///< Corresponds to an angle 3 quarter around the unit circle (3pi/2 radians)
  };
  
  inline const Radians operator+ (const Radians& lhs, const Radians& rhs) {
      return Radians(double(lhs)+double(rhs));
  }
  
  inline const Radians operator- (const Radians& lhs, const Radians& rhs) {
      return Radians(double(lhs)-double(rhs));
  }
  
  inline const Radians operator* (const Radians& lhs, const double& rhs) {
      return Radians(double(lhs)*double(rhs));
  }
  
  inline const Radians operator* (const double& lhs, const Radians& rhs) {
	return rhs*lhs;
  }
  
  inline const Radians operator/ (const Radians& lhs, const double& rhs) {
      return Radians(double(lhs)/double(rhs));
  }
  
  inline const double operator/ (const Radians & lhs, const Radians & rhs) {
      return double(double(lhs)/double(rhs));
  }
  
  const Radians TAO(2*M_PI);  ///< Constant for TAO.

  /// Constant for 360 degrees. Created for type purity purposes. Doubts that it will be used.
  const Degrees ANGLE_360(360.0);
  
  /// Converts from Degrees to Radians
  inline const Radians DEGREES_TO_RAD(const double& d) {
    return (Degrees(d)/ANGLE_360)*TAO;
  }
  
  /// Converts from Radians to Degrees
  inline const Degrees RAD_TO_DEGREES(const double& r) {
    return (Radians(r)/TAO)*ANGLE_360;
  }
  
  /// Radians Degrees function needs to be defined after RAD_TO_DEGREES.
  inline Radians::operator Degrees() {
    return RAD_TO_DEGREES(this->val);
  }
  
  inline Radians::operator const Degrees() const {
    return RAD_TO_DEGREES(this->val);
  }
  
  /// Radians constructor needs to be defined after DEGREES_TO_RAD.
  inline Radians::Radians(const Degrees &other): Scalar<double>(DEGREES_TO_RAD(other)) {}
  
  
  /// Returns the square root of x squared + y squared.
  template<typename T>
  inline const Mag_t<double> pythagoras(const X_t<T> &x, const Y_t<T> &y) {
    return Mag_t<double>(sqrt(x*x + y*y));
  }
  
  /// Returns m times cos theta.
  template<typename T>
  inline const X_t<T> getX(const Mag_t<T>& m, const Radians& theta) {
    return m * cos(theta);
  }
  
  /// Returns m times sin theta.
  template<typename T>
  inline const Y_t<T> getY(const Mag_t<T>& m, const Radians& theta) {
    return m * sin(theta);
  }
  
  /// Returns arc tangent of y/x.
  template<typename T>
  inline const Radians getTheta(const X_t<T>& x, const Y_t<T>& y) {
    if(x == 0.0) {
      if(y > 0.0)
        return Radians(TAO/4.0);
      if(y < 0.0)
        return Radians(3.0*TAO/4.0);
      
      return Radians(9001.0);
    }
    
    if(x < 0.0)
      return Radians(TAO/2.0 + atan(y/x));
    
    return Radians(atan(y/x));
  }
}

#endif