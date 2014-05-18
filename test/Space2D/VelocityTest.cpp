#include "Space2D/Velocity.h"
#include <iostream>
using namespace jer;
using std::cout;
using std::endl;

Velocity makeVelocity(const Mag_t<double> &mag, const Radians &theta, char const *name) {
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
  Velocity a = makeVelocity(Mag_t<double>(1.0), TAO/8.0, "a");
  Velocity b = makeVelocity(Mag_t<double>(1.0), TAO*(3.0/8.0), "b");
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
  printVelocity(a*=5.0,"a");
  cout << "a /= 5" << endl;
  printVelocity(a/=5.0,"a");
}
