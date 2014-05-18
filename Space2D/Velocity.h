#ifndef _VELOCITY_H_
#define _VELOCITY_H_
#include "Vector.h"

namespace jer {

class Velocity: public Point<double>, public Vector {
  public:
    using Point<double>::x;
    using Point<double>::y;
    using Vector::mag;
    using Vector::theta;
    /// Create a velocity from an angle and magnitude
    Velocity(const Mag_t<double> &M, const Radians &t): Vector(M, t), Point<double>(Vector(M, t)) {};
    
    /// Create a velocity from an X and Y
    Velocity(const X_t<double> &x, const Y_t<double> &y): Point<double>(x, y), Vector(Point<double>(x, y)) {};
    
    /// Create a velocity from a point
    Velocity (Point<double> const &p2): Vector(p2), Point<double>(p2) {
          /*Just point constructor function call ^ */   /*  ^ Parent class constructor call   */
    };
    
    /// Create a velocity from a vector
    Velocity (Vector const &v2): Vector(v2), Point<double>(v2) {};
    
    /// Set and return the x-coordinate
    void x(const double &x) override;
        
    /// Set and return the y coordinate
    void y(const double &y) override;
    
    /// Set and return magnitude
    void mag(const double &m) override;
    
    /// Set and return angle. IMPORTANT: theta must be in Radians!
    void theta(const double &theta) override;

    /// Adds vv2 to the velocity and returns a reference to it
    Velocity const& operator+= (Velocity const& vv2) {
      this->X += vv2.x();
      this->Y += vv2.y();
      this->Mag = pythagoras(this->X, this->Y);
      this->Theta = getTheta(this->X, this->Y);
      return *this;
    };

    /// Subtracts vv2 from the velocity
    Velocity const& operator-= (Velocity const& vv2) {
      this->X -= vv2.x();
      this->Y -= vv2.y();
      this->Mag = pythagoras(this->X, this->Y);
      this->Theta = getTheta(this->X, this->Y);
      return *this;
    };

    /// Multiplies the magnitude and x-y of the velocity by scale
    Velocity const& operator*= (const double& scale) {
      this->X *= scale;
      this->Y *= scale;
      this->Mag *= scale;
      return *this;
    };

    /// Divides the magnitude and x-y of the velocity by scale
    Velocity const& operator/= (const double &scale) {
      this->X /= scale;
      this->Y /= scale;
      this->Mag /= scale;
      return *this;
    };

    // returns true if comp conatins the same x and y component as the velocity
    const bool operator== (const Velocity& comp) const {
      return (this->X == comp.x())&&(this->Y == comp.y());
    };

    /// returns true if comp doesn't contain the same x and y component as the velocity
    const bool operator!= (const Velocity& comp) const {
      return !(*this == comp);
    };
};

    inline void Velocity::x(const double &x) {
        this->X = x;
        this->Mag = pythagoras(this->X, this->Y);
        this->Theta = getTheta(this->X, this->Y);
    }
    
    inline void Velocity::y(const double &y) {
        this->Y = y;
        this->Mag = pythagoras(this->X, this->Y);
        this->Theta = getTheta(this->X, this->Y);
    }
    
    inline void Velocity::mag(const double &m) {
        this->X /= this->Mag;
        this->X *= m;
        this->Y /= this->Mag;
        this->Y *= m;
        this->Mag = Mag_t<double>(m);
    }

    inline void Velocity::theta(const double &t) {
        this->X = getX(this->Mag, Radians(t));
        this->Y = getY(this->Mag, Radians(t));
        this->Theta = Radians(t);
    }

    /// Construct and return sum of of this velocity and vv2
    inline Velocity const operator+ (Velocity const& vv1, Velocity const& vv2) {
      return Velocity(vv1) += vv2;
    }

    /// Construct and return difference between this velocity and vv2
    inline Velocity const operator- (Velocity const& vv1, Velocity const& vv2) {
      return Velocity(vv1) += vv2;
    }

    /// Construct and return the velocity with the magnitude and coordinates multiplied by scale
    
    inline Velocity const operator* (Velocity const &vv1, const double& scale) {
      return Velocity(vv1) *= scale;
    }
    
    inline Velocity const operator* (const double& scale, Velocity const &vv1) {
      return vv1*scale;
    }
    
    /// Construct and return the velocity with the magnitude and coordinates divided by scale
    inline Velocity const operator/ (Velocity const& vv1, const double& scale) {
      return Velocity(vv1) /= scale;
    }

}
#endif