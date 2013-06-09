#include "Velocity.h"
#include <iostream>
using namespace Space2D;
using std::cout;
using std::endl;

Velocity makeVelocity(long double const &mag, long double const &theta, char const *name) {
  Velocity lol(mag,theta);
  cout << "Created Velocity " << name << ": (" << lol.x()<< ", " <<
  lol.y() << ") [" << lol.mag() << ", " << lol.theta() << "]" << endl;
  return lol;
}
void printVelocity(Velocity v, char const *name) {
  cout << "Velocity " << name << ": (" << v.x() << ", " << v.y() <<
  ") [" << v.mag() << ", " << v.theta() << "]" << endl;
}
int main( int argc, char *argv[]) {
  Velocity a = makeVelocity(1,M_PI/4,"a");
  Velocity b = makeVelocity(1,M_PI*(3.0L/4.0L),"b");
  cout << "a -= b" << endl;
  a -= b;
  printVelocity(a, "a");
  cout << "a += b" << endl;
  a += b;
  printVelocity(a, "a");
  cout << "a + b" << endl;
  printVelocity(a+b, "a+b");
  cout << "b - a" << endl;
  printVelocity(b-a, "b-a");
  cout << "a *= 5" << endl;
  printVelocity(a*=5,"a");
  cout << "a /= 5" << endl;
  printVelocity(a/=5,"a");
}
