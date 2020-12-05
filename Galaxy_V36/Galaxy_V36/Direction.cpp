#include "Direction.h"

galaxy_v36::service::Vector
galaxy_v36::service::Direction::getPositionDelta() const
{
	return posiotionDelta;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getOpposite() const
{
	return opposite;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getUp()
{
	return up;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getUpRight()
{
	return upRight;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getRight()
{
	return right;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getDownRight()
{
	return downRight;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getDown()
{
	return down;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getDownLeft()
{
	return downLeft;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getLeft()
{
	return left;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::getUpLeft()
{
	return upLeft;
}

const galaxy_v36::service::Direction&
galaxy_v36::service::Direction::get(const std::string& direction)
{
	if (direction == "Up")
		return getUp();
	if (direction == "UpRight")
		return getUpRight();
	if (direction == "Right")
		return getRight();
	if (direction == "DownRight")
		return getDownRight();
	if (direction == "Down")
		return getDown();
	if (direction == "DownLeft")
		return getDownLeft();
	if (direction == "Left")
		return getLeft();

	return getUpLeft();
}

galaxy_v36::service::Direction::Direction(const Vector& posiotionDelta, const Direction& opposite)
	: posiotionDelta(posiotionDelta)
	, opposite(opposite)
{
}

const galaxy_v36::service::Direction& galaxy_v36::service::Direction::up        = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(0,  -1), galaxy_v36::service::Direction::down);
const galaxy_v36::service::Direction& galaxy_v36::service::Direction::upRight   = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(1,  -1), galaxy_v36::service::Direction::downLeft);
const galaxy_v36::service::Direction& galaxy_v36::service::Direction::right     = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(1,   0), galaxy_v36::service::Direction::left);
const galaxy_v36::service::Direction& galaxy_v36::service::Direction::downRight = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(1,   1), galaxy_v36::service::Direction::upLeft);
const galaxy_v36::service::Direction& galaxy_v36::service::Direction::down      = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(0,   1), galaxy_v36::service::Direction::up);
const galaxy_v36::service::Direction& galaxy_v36::service::Direction::downLeft  = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(-1,  1), galaxy_v36::service::Direction::upRight);
const galaxy_v36::service::Direction& galaxy_v36::service::Direction::left      = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(-1,  0), galaxy_v36::service::Direction::right);
const galaxy_v36::service::Direction& galaxy_v36::service::Direction::upLeft    = galaxy_v36::service::Direction::Direction(galaxy_v36::service::Vector(-1, -1), galaxy_v36::service::Direction::downRight);