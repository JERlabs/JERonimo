#ifndef _VELOCITY_H_
#define _VELOCITY_H_
#include "Vector.h"

namespace jer {

template<typename T>
class Velocity: public Point<T>, public Vector<T> {
  public:
    using Point<T>::x;
    using Point<T>::y;
    using Vector<T>::mag;
    using Vector<T>::theta;
    /// Create a velocity from an angle and magnitude
    Velocity(const Mag_t<T> &M, const Radians<T> &t): Vector<T>(M, t), Point<T>(Vector<T>(M, t)) {};
    
    /// Create a velocity from an X and Y
    Velocity(const X_t<T> &x, const Y_t<T> &y): Point<T>(x, y), Vector<T>(Point<T>(x, y)) {};
    
    /// Create a velocity from a point
    Velocity (Point<T> const &p2): Vector<T>(p2), Point<T>(p2) {
          /*Just point constructor function call ^ */   /*  ^ Parent class constructor call   */
    };
    
    /// Create a velocity from a vector
    Velocity (Vector<T> const &v2): Vector<T>(v2), Point<T>(v2) {};
    
    /// Set and return the x-coordinate
    Point<T> &x(const X_t<T> &x);
        
    /// Set and return the y coordinate
    Point<T> &y(const Y_t<T> &y);
    
    /// Set and return magnitude
    Vector<T> &mag(const Mag_t<T> &m);
    
    /// Set and return angle
    Vector<T> &theta(const Radians<T> &theta);

    /// Adds vv2 to the velocity and returns a reference to it
    Velocity<T> const& operator+= (Velocity<T> const& vv2) {
      this->X += vv2.x();
      this->Y += vv2.y();
      this->Mag = pythagoras(this->X, this->Y);
      this->Theta = getTheta(this->X, this->Y);
      return *this;
    };

    /// Subtracts vv2 from the velocity
    Velocity<T> const& operator-= (Velocity<T> const& vv2) {
      this->X -= vv2.x();
      this->Y -= vv2.y();
      this->Mag = pythagoras(this->X, this->Y);
      this->Theta = getTheta(this->X, this->Y);
      return *this;
    };

    /// Multiplies the magnitude and x-y of the velocity by scale
    Velocity<T> const& operator*= (const T& scale) {
      this->X *= scale;
      this->Y *= scale;
      this->Mag *= scale;
      return *this;
    };

    /// Divides the magnitude and x-y of the velocity by scale
    Velocity<T> const& operator/= (const T &scale) {
      this->X /= scale;
      this->Y /= scale;
      this->Mag /= scale;
      return *this;
    };

    // returns true if comp conatins the same x and y component as the velocity
    const bool operator== (const Velocity<T>& comp) const {
      return (this->X == comp.x())&&(this->Y == comp.y());
    };

    /// returns true if comp doesn't contain the same x and y component as the velocity
    const bool operator!= (const Velocity<T>& comp) const {
      return !(*this == comp);
    };
};

    template<typename T>
    Point<T> &Velocity<T>::x(const X_t<T> &x) {
        this->X = x;
        this->Mag = pythagoras(this->X, this->Y);
        this->Theta = getTheta(this->X, this->Y);
        return *this;
    }
    
    template<typename T>
    Point<T> &Velocity<T>::y(const Y_t<T> &y) {
        this->Y = y;
        this->Mag = pythagoras(this->X, this->Y);
        this->Theta = getTheta(this->X, this->Y);
        return *this;
    }
    
    template<typename T>
    Vector<T> &Velocity<T>::mag(const Mag_t<T> &m) {
        this->X /= this->Mag;
        this->X *= this->m;
        this->Y /= this->Mag;
        this->Y *= this->m;
        this->Mag = this->m;
        return *this;
    }

    template<typename T>
    Vector<T> &Velocity<T>::theta(const Radians<T> &t) {
        this->X = getX(this->Mag, t);
        this->Y = getY(this->Mag, t);
        this->Theta = t;
        return *this;
    }

    /// Construct and return sum of of this velocity and vv2
    template<typename T>
    inline Velocity<T> const operator+ (Velocity<T> const& vv1, Velocity<T> const& vv2) {
      return Velocity<T>(vv1) += vv2;
    }

    /// Construct and return difference between this velocity and vv2
    template<typename T>
    inline Velocity<T> const operator- (Velocity<T> const& vv1, Velocity<T> const& vv2) {
      return Velocity<T>(vv1) += vv2;
    }

    /// Construct and return the velocity with the magnitude and coordinates multiplied by scale
    
    template<typename T>
    inline Velocity<T> const operator* (Velocity<T> const &vv1, const T& scale) {
      return Velocity<T>(vv1) *= scale;
    }
    
    template<typename T>
    inline Velocity<T> const operator* (const T& scale, Velocity<T> const &vv1) {
      return vv1*scale;
    }
    
    /// Construct and return the velocity with the magnitude and coordinates divided by scale
    template<typename T>
    inline Velocity<T> const operator/ (Velocity<T> const& vv1, const T& scale) {
      return Velocity<T>(vv1) /= scale;
    }

}
#endif