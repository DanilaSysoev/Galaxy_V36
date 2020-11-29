#include "SpaceBody.h"

galaxy_v36::entities::SpaceBody::SpaceBody(std::string name)
	: name(name)
{
}

std::string 
galaxy_v36::entities::SpaceBody::getName() const
{
	return name;
}

galaxy_v36::entities::SpaceBody::~SpaceBody()
{
}
