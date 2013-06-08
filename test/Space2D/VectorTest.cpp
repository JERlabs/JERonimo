#include <iostream>

#include "Point.h"
#include "Vector.h"

using namespace Space2D;
using std::cout;
using std::endl;

#define PRINT_POINT(p) printPoint(#p, (p))
#define PRINT_VECTOR(v) printVector(#v, (v))

const Vector makeVector(const long double &m, const long double &t, const char * const name) {
  cout<<"Created vector "<<name<<", "<<m<<"<"<<t<<" rad"<<endl;
  return Vector(m, t);
}

void printVector(const char * const name, const Vector &V) {
  cout<<"Vector "<<name<<" has a magnitude of "<<V.mag()<<" at "<<V.theta()<<" rad"<<endl;
}

Point makePoint(long double const &x, long double const &y, char const *name) {
  Point lol = Point(x,y);
  cout << "created point " << name << "(" << lol.x() << ", " 
  << lol.y() << ")\n";
  return lol;
}
void printPoint(char const *name, Point const &point) {
  cout << "Point " << name << " has value: (" << point.x() << ", "
  << point.y() << ")\n";
}

int main(int argc, char *argv[])
{
  Vector a = makeVector(2, ANGLE_UP/3, "a");
  cout<<"Getting X and Y components of a"<<endl;
  PRINT_POINT(a);
  Point b = makePoint(5, 12, "b");
  cout<<"Getting Vector from origin to b"<<endl;
  PRINT_VECTOR(b);
  cout<<"Getting resultant Vector between a and b (a+b)"<<endl;
  PRINT_VECTOR(a+b);
  PRINT_VECTOR(b+a);
  cout<<"c is the resultant vector of a and b (c=a+b)"<<endl;
  Vector c = a+b;
  cout<<"Extending c by a scale of 2 (c*2)"<<endl;
  PRINT_VECTOR(c*2);
  cout<<"Call this destination point d (d=c*2)"<<endl;
  Point d = c*2;
  PRINT_POINT(d);
  cout<<"Getting distance between b and d (d - b)"<<endl;
  PRINT_VECTOR(d-b);
  PRINT_VECTOR(b-d);

  return 0;
}