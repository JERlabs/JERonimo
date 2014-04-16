#include "Space2DTest.h"

typedef float PLANE_TYPE;

int main(int argc, char *argv[]) {
  Point<PLANE_TYPE> a = makePoint<PLANE_TYPE>(4.4,4.4, "a");
  std::cout << "Multiplying a by 5 \n";
  a *= 5;
  printPoint("a", a);
  Point<PLANE_TYPE> b = makePoint<PLANE_TYPE>(5.5,7.7, "b");
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
  std::cout << "Setting a to b\n";
  a = b;
  printPoint("a", a);
  std::cout << "Add a and b \n";
  printPoint("a + b", a+b);
  printPoint("(a+b)-b", (a+b)-b);
  return 0;
}
