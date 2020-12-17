#include "StarGate.h"

using namespace galaxy_v36::entities;
using namespace galaxy_v36::service;


StarGate::StarGate(
	std::string name,
	const service::Vector& position, 
	int diameter, 
	StarSystem* starSystemOfLocation, 
	StarSystem* destinationStarSystem
)
	: SpaceBody(name)
	, position(position)
	, diameter(diameter)
	, starSystemOfLocation(starSystemOfLocation)
	, destinationStarSystem(destinationStarSystem)
{
}

StarSystem* StarGate::getStarSystemOfLocation()
{
	return starSystemOfLocation;
}

StarSystem* StarGate::getDestinationStarSystem()
{
	return destinationStarSystem;
}

Vector StarGate::getPosition() const
{
	return position;
}

int StarGate::getDiameter() const
{
	return diameter;
}
