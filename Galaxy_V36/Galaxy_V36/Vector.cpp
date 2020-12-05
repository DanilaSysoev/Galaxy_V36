#include "Vector.h"

galaxy_v36::service::Vector::Vector()
	: x(0)
	, y(0)
{
}

galaxy_v36::service::Vector::Vector(int x, int y)
	: x(x)
	, y(y)
{
}

int
galaxy_v36::service::Vector::getX() const
{
	return x;
}

int
galaxy_v36::service::Vector::getY() const
{
	return y;
}

galaxy_v36::service::Vector 
galaxy_v36::service::Vector::add(const Vector& vector) const
{
	return Vector(x + vector.getX(), y + vector.getY());
}

galaxy_v36::service::Vector 
galaxy_v36::service::Vector::negate() const
{
	return Vector(-x, -y);
}

galaxy_v36::service::Vector 
galaxy_v36::service::Vector::multiply(double koefficient) const
{
	return Vector(static_cast<long long>(x * koefficient), static_cast<long long>(y * koefficient));
}

int
galaxy_v36::service::Vector::dot(const Vector& vector) const
{
	return x * vector.getX() + y * vector.getY();
}

int
galaxy_v36::service::Vector::squareLength() const
{
	return x * x + y * y;
}

int
galaxy_v36::service::Vector::sqaureDistance(const Vector& vector) const
{
	return (x - vector.getX()) * (x - vector.getX()) + (y - vector.getY()) * (y - vector.getY());
}

bool 
galaxy_v36::service::Vector::operator<(const Vector& ro) const
{
	return x < ro.getX() || 
		   x == ro.getX() && y < ro.getY();
}

bool
galaxy_v36::service::Vector::operator<=(const Vector& ro) const
{
	return *this < ro || *this == ro;
}

bool
galaxy_v36::service::Vector::operator>(const Vector& ro) const
{
	return !(*this <= ro);
}

bool
galaxy_v36::service::Vector::operator>=(const Vector& ro) const
{
	return !(*this < ro);
}

bool 
galaxy_v36::service::Vector::operator==(const Vector& ro) const
{
	return x == ro.getX() && y == ro.getY();
}

bool 
galaxy_v36::service::Vector::operator!=(const Vector& ro) const
{
	return !(*this == ro);
}

const galaxy_v36::service::Vector&
galaxy_v36::service::Vector::getZero()
{
	return galaxy_v36::service::Vector::zero;
}

const galaxy_v36::service::Vector& galaxy_v36::service::Vector::zero = galaxy_v36::service::Vector();