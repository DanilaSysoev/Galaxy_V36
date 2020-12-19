#include "SpaceBody.h"

using namespace galaxy_v36::entities;

SpaceBody::SpaceBody(std::string name, std::string type)
	: name(name)
	, type(type)
{
}

std::string 
SpaceBody::getName() const
{
	return name;
}

std::string galaxy_v36::entities::SpaceBody::getType() const
{
	return type;
}

bool SpaceBody::isInside(const service::Vector& point)
{
	return getPosition().sqaureDistance(point) < (getDiameter() * getDiameter()) / 4;
}

SpaceBody::~SpaceBody()
{
}
