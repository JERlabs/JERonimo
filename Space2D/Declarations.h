#ifndef _SPACE_2D_H_
#define _SPACE_2D_H_

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
#define M_PI		3.14159265358979323846
#endif
typedef double PIXEL_TYPE;

namespace jer {  
  class Vector;   // forward declaration of vector
  template<typename T> class Point;  // forward declaration of Point, a template class (depending on the chosen units)
  
  
  /** Base class for Scalar Types, which covers autoboxing of the value it holds of type T.
   * T should support arithmetic operators, comparative operators, and assignment operators.
   */
  template<typename T>
  class Scalar {
  protected:
    T val; 
    
  public:
	/// Returns address of contained value.
    T * const getPtr() {return &val;};
    const T * const getPtr() const {return &val;};
	
	/// Implicit conversion operator to T
    operator T&() {return val;};
    operator const T&() const {return val;};
	
	/// Default constructor
    Scalar(): val(T(0.0)) {};
	
	/// Composite constructor
    Scalar(const T& v): val(v) {};
	
	/// Copy constructor
    Scalar(const Scalar &other): val(other.val) {};
  };
  
    /** Specialization of Scalar for squared Scalar values.
	 * Also autoboxes to T, such that things like x*x + y*y are legal
	 */
  template<typename T>
  class Scalar<Scalar<T> > {
	protected:
	  Scalar<T> val;
	
	public:
	  /// Returns address of contained value.
	  T * const getPtr() {return &val;};
	  const T * const getPtr() const {return &val;};
	
	  /// Implicit conversion operator to T
	  operator T&() {return val;};
	  operator const T&() const {return val;};
	  
	  /// Default constructor
	  Scalar(): val(Scalar<T>(0.0)) {};
	  
	  /// Composite constructor
	  Scalar(const T& v): val(Scalar<T>(v)) {};
	  Scalar(const Scalar<T> &other): val(other) {};
	  
	  /// Copy constructor
	  Scalar(const Scalar<Scalar<T> >& other): val(other) {};
  };
  
  /// Overload of the multiplication of two Scalar values resulting in a squared Scalar value (Scalar of Scalars)  
  template<typename T>
  const Scalar<Scalar<T> > operator* (const Scalar<T>& lhs, const Scalar<T>& rhs) {
	return lhs*T(rhs);
  }

  /// Scalar class representing X coordinate values  
  template<typename T>
  class X_t: public Scalar<T> {
  public:
    X_t(): Scalar<T>() {};  ///< Default constructor
    X_t(const T& x): Scalar<T>(x) {};  ///< Constructor
    X_t(const Scalar<T> &other): Scalar<T>(other) {};  ///< Constructor
  };
  
  /// Scalar class representing Y coordinate values
  template<typename T>
  class Y_t: public Scalar<T> {
  public:
      Y_t(): Scalar<T>() {};  ///< Default constructor
      Y_t(const T& y): Scalar<T>(y) {};   ///< Constructor
      Y_t(const Scalar<T> &other): Scalar<T>(other) {};   ///< Constructor
  };

  /// Scalar class representing magnitudes or hypotenuses  
  template<typename T>
  class Mag_t: public Scalar<T> {
  public:
    Mag_t(): Scalar<T>() {};   ///< Default constructor
	
	/** Composite constructor.
	 * This constructor is explicit so that types aren't mixed due to autoboxing. 
	 * For example, in Vector's constructor which takes a Mag_t object and Radians object which both have single-argument-T constructors
	*/
    explicit Mag_t(const T& m): Scalar<T>(m) {};
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
  
  /// Class representing degree measures of angles, stored as doubles.
  class Degrees: public Scalar<double> {
  public:
      /** Implicit conversion operator to T
       * Overloads Scalar because it ensures that the value is within the correct range
       */
      void validate()
      {
          // Keep val between -180 and 180
          while(val >= 180.0) val -= 360.0;
          while(val < -180.0) val += 360.0;
      }
      
  public:
    Degrees(): Scalar<double>() {}; ///< Default constructor
	/** Constructor
	 * Made explicit so client doesn't confuse Degrees and Radians when passing in angle values.
	 */
    explicit Degrees(const double& a=0.0): Scalar<double>(a) {};
    // not sure exactly why this is here, I'm removing it for now
    //Degrees(const Mag_t &other): Scalar(other) {};  
	/** Constructor
	 * Made explicit so client doesn't confuse Degrees and Radians when passing in angle values.
	 */
    explicit Degrees(const Scalar<double> &other): Scalar<double>(other) {};
    
    /// Copy constructor
    Degrees(const Degrees& other): Scalar<double>(other) {};
    
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

  /// Class representing radian measures of angles, stored as doubles.
  class Radians: public Scalar<double> {
  public:
      /** Implicit conversion operator to T
       * Overloads Scalar because it ensures that the value is within the correct range
       */
      void validate()
      {
          // Keep val between -PI and PI
          while(val >= M_PI) val -= 2*M_PI;
          while(val < -M_PI) val += 2*M_PI;
      }
	/** Cast operator to Degrees.
	 * This allows implicit casts between Radians and Degrees, converting their values appropriately.
	 */
    operator Degrees();
    operator const Degrees() const;   ///< Constant cast operator to Degrees.
    Radians(): Scalar<double>() {};	///< Default constructor
	/** Constructor
	 * Explicit so that Radian and Degree values aren't confused when passing angles to objects
	 */
    explicit Radians(const double &a): Scalar<double>(a) {};
	/** Constructor
	 * This allows implicit casts between Degrees and Radians, converting their values appropriately.
	 * @see operator Degrees()
	 */
    Radians(const Degrees &other);
	/** Constructor
	 * Explicit so that Radian and Degree values aren't confused when passing angles to objects.
	 */
    explicit Radians(const Scalar<double> &other): Scalar<double>(other) {};
    
    /// Copy constructor
    Radians(const Radians& other): Scalar<double>(other) {};
  
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
  
  /// Constant for TAO.
  const Radians TAO(2*M_PI);

  /// Constant for 360 degrees used for type purity.
  const Degrees ANGLE_360(360.0);
  
  /// Converts from Degrees to Radians
  inline const Radians DEGREES_TO_RAD(const double& d) {
    return (Degrees(d)/ANGLE_360)*TAO;
  }
  
  /// Converts from Radians to Degrees
  inline const Degrees RAD_TO_DEGREES(const double& r) {
    return (Radians(r)/TAO)*ANGLE_360;
  }
  
  // Radians Degrees function needs to be defined after RAD_TO_DEGREES.
  inline Radians::operator Degrees() {
    return RAD_TO_DEGREES(this->val);
  }
  
  inline Radians::operator const Degrees() const {
    return RAD_TO_DEGREES(this->val);
  }
  
  // Radians constructor needs to be defined after DEGREES_TO_RAD.
  inline Radians::Radians(const Degrees &other): Scalar<double>(DEGREES_TO_RAD(other)) {}
  
  
  /// Finds the hypotenuse of a right-triangles with x and y as legs
  template<typename T>
  inline const Mag_t<double> pythagoras(const X_t<T> &x, const Y_t<T> &y) {
    return Mag_t<double>(sqrt(x*x + y*y));
  }
  
  /// Finds the x component of a vector with magnitude m and angle theta.
  template<typename T>
  inline const X_t<T> getX(const Mag_t<T>& m, const Radians& theta) {
    return m * cos(theta);
  }
  
  /// Finds the y component of a vector with magnitude m and angle theta.
  template<typename T>
  inline const Y_t<T> getY(const Mag_t<T>& m, const Radians& theta) {
    return m * sin(theta);
  }
  
  /// Finds the angle of the hypotenuse of a right triangle formed by legs of lengths x and y.
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