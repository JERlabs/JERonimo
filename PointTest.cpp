#include <iostream>
#include "Point.h"
using namespace Space2D;

Point makePoint(long double const &x, long double const &y, char const *name) {
  Point lol = Point(x,y);
  std::cout << "created point " << name << "(" << lol.x() << "," 
  << lol.y() << ")\n";
  return lol;
}
void printPoint(char const *name, Point &point) {
  std::cout << "Point " << name << " has value: (" << point.x() << ","
  << point.y() << ")\n";
}
int main(int argc, char *argv[]) {
  Point a = makePoint(4,4, "a");
  std::cout << "Multiplying a by 5 \n";
  a *= 5;
  printPoint("a", a);
  Point b = makePoint(5,7, "b");
  std::cout << "Subtracting point b from point a\n";
  a -= b;
  printPoint("a", a);
  std::cout << "Adding point b to point a\n";
  a += b;
  printPoint("a", a);
  std::cout << "checking inequality of points a & b: " << (a != b) << "\n";
  std::cout << "checking equality of a & b: " << (a == b) << "\n";
  std::cout << "Dividing a by 5 \n";
  a /= 5;
  printPoint("a", a);
  return 0;
}
