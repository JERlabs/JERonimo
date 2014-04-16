#ifndef _SPACE2D_TEST_H_
#define _SPACE2D_TEST_H_

#include <iostream>

#include "Space2D.h"

using namespace jer;
using std::cout;
using std::endl;

#define PRINT_POINT(p) printPoint(#p, (p))
#define PRINT_VECTOR(v) printVector(#v, (v))

template<typename T>
const Vector<T> makeVector(const Mag_t<T> &m, const Radians<T> &t, const char * const name) {
  cout<<"Created vector "<<name<<", "<<m<<"<"<<t<<" rad"<<endl;
  return Vector<T>(m, t);
}

template<typename T>
void printVector(const char * const name, const Vector<T> &V) {
  cout<<"Vector "<<name<<" has a magnitude of "<<V.mag()<<" at "<<V.theta()<<" rad"<<endl;
}

template<typename T>
Point<T> makePoint(const X_t<T> &x, const Y_t<T> &y, char const *name) {
  Point<T> lol = Point<T>(x,y);
  cout << "created point " << name << "(" << lol.x() << ", " 
  << lol.y() << ")\n";
  return lol;
}

template<typename T>
void printPoint(char const *name, Point<T> const &point) {
  cout << "Point " << name << " has value: (" << point.x() << ", "
  << point.y() << ")\n";
}

#endif /*SPACE2D_TEST_H_*/
