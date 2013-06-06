namespace Space2D {

class Point {
  private:
    long double X;
    long double Y;
  public:
    Point (long double, long double);
    Point (int, int);
    long double x();
    long double x(long double);
    int x(int);
    long double y();
    long double y(long double);
    int y(int);
    Point operator + (Point);
    Point operator - (Point);
    Point operator * (long double);
    Point operator * (int);
    Point operator / (long double);
    Point operator / (int);
    Point operator += (Point);
    Point operator -= (Point);
    Point operator *= (long double);
    Point operator *= (int);
    Point operator /= (long double);
    Point operator /= (int);
};

}
