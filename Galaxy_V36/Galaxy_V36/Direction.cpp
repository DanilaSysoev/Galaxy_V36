#include "Direction.h"

using namespace galaxy_v36::service;


Vector Direction::getPositionDelta() const
{
	return posiotionDelta;
}

const Direction& Direction::getOpposite() const
{
	return opposite;
}

const Direction& Direction::getUp()
{
	return up;
}

const Direction& Direction::getUpRight()
{
	return upRight;
}

const Direction& Direction::getRight()
{
	return right;
}

const Direction& Direction::getDownRight()
{
	return downRight;
}

const Direction& Direction::getDown()
{
	return down;
}

const Direction& Direction::getDownLeft()
{
	return downLeft;
}

const Direction& Direction::getLeft()
{
	return left;
}

const Direction& Direction::getUpLeft()
{
	return upLeft;
}

const Direction& Direction::get(const std::string& direction)
{
	if (direction == UP_STRING)
		return getUp();
	if (direction == UP_RIGHT_STRING)
		return getUpRight();
	if (direction == RIGHT_STRING)
		return getRight();
	if (direction == DOWN_RIGHT_STRING)
		return getDownRight();
	if (direction == DOWN_STRING)
		return getDown();
	if (direction == DOWN_LEFT_STRING)
		return getDownLeft();
	if (direction == LEFT_STRING)
		return getLeft();

	return getUpLeft();
}

Direction::Direction(const Vector& posiotionDelta, const Direction& opposite)
	: posiotionDelta(posiotionDelta)
	, opposite(opposite)
{
}

const Direction& Direction::up =
    Direction::Direction(Vector(0,  -1), Direction::down);
const Direction& Direction::upRight =
    Direction::Direction(Vector(1,  -1), Direction::downLeft);
const Direction& Direction::right =
    Direction::Direction(Vector(1,   0), Direction::left);
const Direction& Direction::downRight =
    Direction::Direction(Vector(1,   1), Direction::upLeft);
const Direction& Direction::down =
    Direction::Direction(Vector(0,   1), Direction::up);
const Direction& Direction::downLeft =
    Direction::Direction(Vector(-1,  1), Direction::upRight);
const Direction& Direction::left =
    Direction::Direction(Vector(-1,  0), Direction::right);
const Direction& Direction::upLeft =
    Direction::Direction(Vector(-1, -1), Direction::downRight);

const std::string Direction::UP_STRING = "Up";
const std::string Direction::UP_RIGHT_STRING = "UpRight";
const std::string Direction::RIGHT_STRING = "Right";
const std::string Direction::DOWN_RIGHT_STRING = "DownRight";
const std::string Direction::DOWN_STRING = "Down";
const std::string Direction::DOWN_LEFT_STRING = "DownLeft";
const std::string Direction::LEFT_STRING = "Left";
const std::string Direction::UP_LEFT_STRING = "UpLeft";