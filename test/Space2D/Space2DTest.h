#ifndef _SPACE2D_TEST_H_
#define _SPACE2D_TEST_H_

#include <iostream>

#include "Space2D/Point.h"
#include "Space2D/Vector.h"

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

#endif /*SPACE2D_TEST_H_*/
