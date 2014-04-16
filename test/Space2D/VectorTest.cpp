#include "Space2DTest.h"

typedef float PLANE_TYPE;

int main(int argc, char *argv[])
{
  Vector<PLANE_TYPE> a = makeVector<PLANE_TYPE>(Mag_t<PLANE_TYPE>(2.0), Radians<PLANE_TYPE>(Radians<PLANE_TYPE>::ANGLE_UP/3.0), "a");
  cout<<"Getting X and Y components of a"<<endl;
  PRINT_POINT(a);
  Point<PLANE_TYPE> b = makePoint<PLANE_TYPE>(5.0, 12.0, "b");
  cout<<"Getting Vector from origin to b"<<endl;
  PRINT_VECTOR(b);
  cout<<"Getting resultant Vector between a and b (a+b)"<<endl;
  PRINT_VECTOR(a+b);
  PRINT_VECTOR(b+a);
  cout<<"c is the resultant vector of a and b (c=a+b)"<<endl;
  Vector<PLANE_TYPE> c = a+b;
  cout<<"Extending c by a scale of 2 (c*2)"<<endl;
  PRINT_VECTOR(c*2);
  cout<<"Call this destination point d (d=c*2)"<<endl;
  Point d<PLANE_TYPE> = c*2;
  PRINT_POINT(d);
  cout<<"Getting distance between b and d (d - b)"<<endl;
  PRINT_VECTOR(d-b);
  PRINT_VECTOR(b-d);

  return 0;
}