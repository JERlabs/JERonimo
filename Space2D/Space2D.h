#ifndef _SPACE_2D_H_
#define _SPACE_2D_H_

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
#define M_PI		3.14159265358979323846
#endif /* M_PI */
#define TAO 2*M_PI

#define ANGLE_RIGHT 0.0
#define ANGLE_UP TAO/4.0
#define ANGLE_LEFT TAO/2.0
#define ANGLE_DOWN 3.0*TAO/4.0


namespace Space2D {	
  /*space containing code related to 2D space algorithm 
  * such as coordinate plane geometry, vector math, 
  * and certain physics calculations */
  
  class Point;	//class containing X and Y components
  class Vector;	//class containing Magnitude and Direction components
  class Velocity;	//class inheriting Vector and Point
}


#endif
