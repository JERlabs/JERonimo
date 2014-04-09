#include "Declarations.h"

namespace jer {
  
/** Constant definitions
 */

template<typename T> const Degrees<double> Degrees<T>::ANGLE_RIGHT(0.0);
template<typename T> const Degrees<double> Degrees<T>::ANGLE_UP(90.0);
template<typename T> const Degrees<double> Degrees<T>::ANGLE_LEFT(180.0);
template<typename T> const Degrees<double> Degrees<T>::ANGLE_DOWN(270.0);

template<typename T> const Radians<double> Radians<T>::ANGLE_RIGHT(0.0);
template<typename T> const Radians<double> Radians<T>::ANGLE_UP(TAO/4.0);
template<typename T> const Radians<double> Radians<T>::ANGLE_LEFT(TAO/2.0);
template<typename T> const Radians<double> Radians<T>::ANGLE_DOWN(3.0*TAO/4.0);

}
