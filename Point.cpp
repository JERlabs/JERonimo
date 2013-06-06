#include "Point.h"
namespace Space2D {

Point::Point (long double x, long double y) {
  X = x;
  Y = y;
}
long double Point::x() {
  return X;
}
long double Point::x(long double x) {
  X = x;
  return X;
}
long double Point::y() {
  return Y;
}
long double Point::y(long double y) {
  Y = y;
  return Y;
}

Point Point::operator+ (Point p2) {
  return Point (X + p2.x(),Y + p2.y());
}
Point Point::operator- (Point p2) {
  return Point (X - p2.x(),Y - p2.y());
}
Point Point::operator * (long double scale) {
  return Point (X * scale, Y * scale);
}
Point Point::operator / (long double scale) {
  return Point (X/scale, Y/scale);
}
Point Point::operator += (Point p2) {
  X += p2.x();
  Y += p2.y();
}
Point Point::operator -= (Point p2) {
  X -= p2.x();
  Y -= p2.y();
}
Point Point::operator *= (long double scale) {
  X *= scale;
  Y *= scale;
}
Point Point::operator /= (long double scale) {
  X /= scale;
  Y /= scale;
}
bool Point::operator == (Point p2) {
  return (X == p2.x())&&(Y == p2.y());
}
bool Point::operator != (Point p2) {
  return (X != p2.x())||(Y != p2.y());
}
}
