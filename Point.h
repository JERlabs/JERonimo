namespace Space2D {

class Point {
  private:
    long double X;
    long double Y;
  public:
    Point (long double, long double);
    long double x();
    long double x(long double);
    long double y();
    long double y(long double);
    Point operator + (Point);
    Point operator - (Point);
    Point operator * (long double);
    Point operator / (long double);
    Point operator += (Point);
    Point operator -= (Point);
    Point operator *= (long double);
    Point operator /= (long double);
    Point operator == (Point);
    Point operator != (Point);
};

}
