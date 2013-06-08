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
	Point const operator * (const long double &scale) const;
	Point const operator / (const long double &scale) const;
	Vector& operator = (Vector const&);
	Vector& operator += (Point const&);
	Vector& operator -= (Point const&);
	Vector& operator *= (const long double &scale);
	Vector& operator /= (const long double &scale);
	const bool operator == (Vector const &) const;
	const bool operator != (Vector const &) const;
};

}

#endif
