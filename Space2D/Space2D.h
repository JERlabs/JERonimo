#ifndef _SPACE_2D_H_
#define _SPACE_2D_H_

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define M_PI		3.14159265358979323846
typedef double PIXEL_TYPE;

namespace Space2D {
  /*space containing code related to 2D space algorithm 
  * such as coordinate plane geometry, vector math, 
  * and certain physics calculations 
  */
  struct X_t;
  struct Y_t;
  struct Mag_t;
  struct Degrees;
  struct Radians;
  class Point;		//class containing X and Y components
  class Vector;		//class containing Magnitude and Direction components
  class Velocity;	//class inheriting Vector and Point
  
  struct Scalar {
    PIXEL_TYPE val;
    operator PIXEL_TYPE() const {return val;};
    const Scalar& operator+= (const PIXEL_TYPE& rhs);
    const Scalar& operator+= (const Scalar& rhs) {return *this+=rhs.val;};
    const Scalar& operator-= (const PIXEL_TYPE& rhs);
    const Scalar& operator-= (const Scalar& rhs) {return *this-=rhs.val;};
    const Scalar& operator*= (const PIXEL_TYPE& rhs);
    const Scalar& operator/= (const PIXEL_TYPE& rhs);
    const Scalar& operator=  (const PIXEL_TYPE& rhs);
    const Scalar& operator=  (const Scalar& rhs) {return *this=rhs.val;};
  public:
    Scalar(const PIXEL_TYPE v=0): val(v) {};
    Scalar(const Scalar &other): val(other.val) {};
  };
  
  inline const Scalar& Scalar::operator+= (const PIXEL_TYPE& rhs) {
    val+=rhs;
    return *this;
  }
  
  inline const Scalar& Scalar::operator-= (const PIXEL_TYPE& rhs) {
    val-=rhs;
    return *this;
  }
  
  inline const Scalar& Scalar::operator*= (const PIXEL_TYPE& rhs) {
    val*=rhs;
    return *this;
  }
  
  inline const Scalar& Scalar::operator/= (const PIXEL_TYPE& rhs) {
    val/=rhs;
    return *this;
  }
  
  inline const Scalar& Scalar::operator= (const PIXEL_TYPE& rhs) {
    val = rhs;
    return *this;
  }
  
  inline const Scalar operator- (const Scalar& rhs) {
    return Scalar(-rhs.val);
  }
  
  inline const Scalar operator+ (const Scalar& lhs, const Scalar& rhs) {
    return Scalar(lhs)+=rhs;
  }
  
  inline const Scalar operator+ (const Scalar& lhs, const PIXEL_TYPE& rhs) {
    return Scalar(lhs)+=rhs;
  }
  
  inline const Scalar operator+ (const PIXEL_TYPE& lhs, const Scalar& rhs) {
    return rhs+lhs;
  }
  
  inline const Scalar operator- (const Scalar& lhs, const Scalar& rhs) {
    return Scalar(lhs)-=rhs;
  }
  
  inline const Scalar operator- (const Scalar& lhs, const PIXEL_TYPE& rhs) {
    return Scalar(lhs)-=rhs;
  }
  
  inline const Scalar operator- (const PIXEL_TYPE lhs, const Scalar& rhs) {
    return rhs - lhs;
  }
  
  inline const Scalar operator* (const Scalar& lhs, const PIXEL_TYPE& rhs) {
    return Scalar(lhs)*=rhs;
  }
  
  inline const Scalar operator* (const PIXEL_TYPE& lhs, const Scalar& rhs) {
    return rhs * lhs;
  }
  
  inline const Scalar operator/ (const Scalar& lhs, const PIXEL_TYPE& rhs) {
    return Scalar(lhs)/=rhs;
  }
  
  inline const PIXEL_TYPE operator/ (const Scalar& lhs, const Scalar& rhs) {
    return lhs.val / rhs.val;
  }
  
  /*
  inline const bool operator== (const Scalar& lhs, const Scalar& rhs) {
    return lhs.val==rhs.val;
  }
  
  inline const bool operator== (const Scalar& lhs, const PIXEL_TYPE& rhs) {
    return lhs.val==rhs;
  }
  
  inline const bool operator== (const PIXEL_TYPE& lhs, const Scalar& rhs) {
    return rhs==lhs;
  }
  
  inline const bool operator!= (const Scalar& lhs, co
  nst Scalar& rhs) {
    return !(lhs==rhs);
  }
  
  inline const bool operator!= (const Scalar& lhs, const PIXEL_TYPE& rhs) {
    return !(lhs==rhs);
  }
  
  inline const bool operator!= (const PIXEL_TYPE& lhs, const Scalar& rhs) {
    return rhs!=lhs;
  }
  
  */
  
  struct X_t: public Scalar {
    X_t(const PIXEL_TYPE x=0): Scalar(x) {};
    X_t(const X_t &other): Scalar(other) {};
    X_t(const Scalar &other): Scalar(other) {};
  };

  struct Y_t: public Scalar{
    Y_t(const PIXEL_TYPE y=0): Scalar(y) {};
    Y_t(const Y_t &other): Scalar(other) {};
    Y_t(const Scalar &other): Scalar(other) {};
  };
  
  struct Mag_t: public Scalar {
    using Scalar::operator=;
    explicit Mag_t(const PIXEL_TYPE m=0): Scalar(m) {};
    Mag_t(const Mag_t &other): Scalar(other) {};
    Mag_t(const Scalar &other): Scalar(other) {};
  };
  
  struct Degrees: public Scalar {
    explicit Degrees(const PIXEL_TYPE a=0): Scalar(a) {};
    Degrees(const Mag_t &other): Scalar(other) {};
    Degrees(const Scalar &other): Scalar(other) {};
    
    static const Degrees ANGLE_RIGHT;
    static const Degrees ANGLE_UP;
    static const Degrees ANGLE_LEFT;
    static const Degrees ANGLE_DOWN;
  };
  
  struct Radians: public Scalar {
    operator Degrees() const;
    explicit Radians(const PIXEL_TYPE a=0): Scalar(a) {};
    Radians(const Radians &other): Scalar(other) {};
    Radians(const Degrees &other);
    Radians(const Scalar &other): Scalar(other) {};
  
    static const Radians ANGLE_RIGHT;
    static const Radians ANGLE_UP;
    static const Radians ANGLE_LEFT;
    static const Radians ANGLE_DOWN;
  };
  
  const Radians TAO(2*M_PI);  ///< Constant for TAO.
  const Degrees ANGLE_360(360.0);  ///< Constant for 360 degrees. Created for type purity purposes. Doubts that it will be used.
  
  /// Converts from Degrees to Radians
  inline const Radians DEGREES_TO_RAD(PIXEL_TYPE d) {
    return (d/ANGLE_360.val)*TAO;
  }
  
  /// Converts from Radians to Degrees
  inline const Degrees RAD_TO_DEGREES(PIXEL_TYPE r) {
    return (r/TAO.val)*ANGLE_360;
  }
  
  /// Radians Degrees function needs to be defined after RAD_TO_DEGREES.
  inline Radians::operator Degrees() const {
    return RAD_TO_DEGREES(val);
  }
  
  /// Radians constructor needs to be defined after DEGREES_TO_RAD.
  inline Radians::Radians(const Degrees &other): Scalar(DEGREES_TO_RAD(other.val)) {}
  
  
  /// Returns the square root of x squared + y squared.
  inline const PIXEL_TYPE pythagoras(const PIXEL_TYPE &x, const PIXEL_TYPE &y) {
    return sqrt(x*x + y*y);
  }
  
  /// Returns m times cos theta.
  inline const PIXEL_TYPE getX(const Mag_t& m, const Radians& theta) {
    return m * cos(theta);
  }
  
  /// Returns m times sin theta.
  inline const PIXEL_TYPE getY(const Mag_t& m, const Radians& theta) {
    return m * sin(theta);
  }
  
  /// Returns arc tangent of y/x.
  inline const Radians getTheta(const X_t& x, const Y_t& y) {
    if(x == 0) {
      if(y > 0)
        return Radians(Radians::ANGLE_UP);
      if(y < 0)
        return Radians(Radians::ANGLE_DOWN);
      
      return Radians(9001);
    }
    
    if(x < 0)
      return Radians(Radians::ANGLE_LEFT + atan(y/x));
    
    return Radians(atan(y/x));
  }
}


#endif