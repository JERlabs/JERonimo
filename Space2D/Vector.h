#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Space2D.h"

namespace Space2D
{

class Vector {
private:
	long double Mag;
	long double Theta;
public:
	Vector(long double const &magInit, long double const &thetaInit);
	Vector(Vector const &v2);	
	Vector(const Point &p2);
	Vector();
public:
	const long double mag() const;
	const long double mag(const long double &m);
	const long double theta() const;
	const long double theta(const long double &t);
public:
	Point const operator + (Point const&) const;
	Point const operator - (Point const&) const;
	Point const operator * (Point const&) const;
	Point const operator / (Point const&) const;
	Vector& const operator = (Vector const&);
	Vector& const operator += (Point const&);
	Vector& const operator -= (Point const&);
	Vector& const operator *= (Point const&);
	Vector& const operator /= (Point const&);
	const bool operator == (Vector const &);
	const bool operator != (Vector const &);
};

}

#endif
