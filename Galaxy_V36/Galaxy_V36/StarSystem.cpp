#include "SpaceBody.h"
#include "StarSystem.h"

using namespace galaxy_v36::service;
using namespace galaxy_v36::entities;

StarSystem::StarSystem(
	const std::string& name, 
	const Vector& position,
	std::vector<SpaceBody*> spaceBodies
)
	: name(name)
	, position(position)
	, spaceBodies(spaceBodies)
	, spaceBodiesNamed()
	, spaceBodiesPositioned()	
{
	for (auto spaceBody : spaceBodies) {
		spaceBodiesNamed[spaceBody->getName()] = spaceBody;
		spaceBodiesPositioned[spaceBody->getPosition()] = spaceBody;
	}
}

std::string StarSystem::getName() const
{
	return name;
}

Vector StarSystem::getPosition() const
{
	return position;
}

int StarSystem::getSpaceBodiesCount() const
{
	return spaceBodies.size();
}

SpaceBody* StarSystem::getSpaceBody(int index) const
{
	return spaceBodies[index];
}

SpaceBody* StarSystem::getSpaceBody(const std::string& name) const
{
	auto spaceBodyIterator = spaceBodiesNamed.find(name);
	if (spaceBodyIterator == spaceBodiesNamed.end())
		return nullptr;

	return spaceBodyIterator->second;
}

SpaceBody* StarSystem::getSpaceBody(const service::Vector& position) const
{
	auto spaceBodyIterator = spaceBodiesPositioned.find(position);
	if (spaceBodyIterator == spaceBodiesPositioned.end())
		return nullptr;

	return spaceBodyIterator->second;
}

StarSystem::~StarSystem()
{
	for (auto spaceBody : spaceBodies)
		delete spaceBody;
}
