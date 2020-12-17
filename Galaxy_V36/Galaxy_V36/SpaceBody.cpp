#include "SpaceBody.h"

using namespace galaxy_v36::entities;

SpaceBody::SpaceBody(std::string name)
	: name(name)
{
}

std::string 
SpaceBody::getName() const
{
	return name;
}

bool SpaceBody::isInside(const service::Vector& point)
{
	return getPosition().sqaureDistance(point) < (getDiameter() * getDiameter()) / 4;
}

SpaceBody::~SpaceBody()
{
}
