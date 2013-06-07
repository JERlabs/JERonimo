#include "Point.h"
namespace Space2D {

Point::Point (long double const &x, long double const &y) {
  X = x;
  Y = y;
}
long double Point::x() const{
  return X;
}
long double Point::x(long double const &x) {
  X = x;
  return X;
}
long double Point::y() const{
  return Y;
}
long double Point::y(long double const &y) {
  Y = y;
  return Y;
}

Point Point::operator+ (Point const &p2) const{
  return Point (X + p2.x(),Y + p2.y());
}
Point Point::operator- (Point const &p2) const{
  return Point (X - p2.x(),Y - p2.y());
}
Point Point::operator * (long double const &scale) const{
  return Point (X * scale, Y * scale);
}
Point Point::operator / (long double const &scale) const{
  return Point (X/scale, Y/scale);
}
Point Point::operator += (Point const &p2) {
  X += p2.x();
  Y += p2.y();
}
Point Point::operator -= (Point const &p2) {
  X -= p2.x();
  Y -= p2.y();
}
Point Point::operator *= (long double const &scale) {
  X *= scale;
  Y *= scale;
}
Point Point::operator /= (long double const &scale) {
  X /= scale;
  Y /= scale;
}
bool Point::operator == (Point const &p2) const{
  return (X == p2.x())&&(Y == p2.y());
}
bool Point::operator != (Point const &p2) const{
  return (X != p2.x())||(Y != p2.y());
}
}
