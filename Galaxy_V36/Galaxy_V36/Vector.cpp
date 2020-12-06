#include "Vector.h"

using namespace galaxy_v36::service;


Vector::Vector()
	: x(0)
	, y(0)
{
}

Vector::Vector(int x, int y)
	: x(x)
	, y(y)
{
}

int Vector::getX() const
{
	return x;
}

int Vector::getY() const
{
	return y;
}

Vector Vector::add(const Vector& vector) const
{
	return Vector(x + vector.getX(), y + vector.getY());
}

Vector Vector::negate() const
{
	return Vector(-x, -y);
}

Vector Vector::multiply(double koefficient) const
{
	return Vector(
		static_cast<long long>(x * koefficient), 
		static_cast<long long>(y * koefficient)
	);
}

int Vector::dot(const Vector& vector) const
{
	return x * vector.getX() + y * vector.getY();
}

int Vector::squareLength() const
{
	return x * x + y * y;
}

int Vector::sqaureDistance(const Vector& vector) const
{
	return (x - vector.getX()) * (x - vector.getX()) + 
		   (y - vector.getY()) * (y - vector.getY());
}

bool Vector::operator<(const Vector& ro) const
{
	return x < ro.getX() || 
		   x == ro.getX() && y < ro.getY();
}

bool Vector::operator<=(const Vector& ro) const
{
	return *this < ro || *this == ro;
}

bool Vector::operator>(const Vector& ro) const
{
	return !(*this <= ro);
}

bool Vector::operator>=(const Vector& ro) const
{
	return !(*this < ro);
}

bool Vector::operator==(const Vector& ro) const
{
	return x == ro.getX() && y == ro.getY();
}

bool Vector::operator!=(const Vector& ro) const
{
	return !(*this == ro);
}

const Vector& Vector::getZero()
{
	return Vector::zero;
}

const Vector& Vector::zero = Vector();