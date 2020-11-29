#include "SpaceBody.h"
#include "StarSystem.h"

galaxy_v36::entities::StarSystem::StarSystem(std::vector<SpaceBody*> spaceBodies)
	: spaceBodies(spaceBodies)
	, spaceBodiesNamed()
	, spaceBodiesPositioned()
{
	for (auto spaceBody : spaceBodies) {
		spaceBodiesNamed[spaceBody->getName()] = spaceBody;
		spaceBodiesPositioned[spaceBody->getPosition()] = spaceBody;
	}
}

std::string
galaxy_v36::entities::StarSystem::getName() const
{
	return name;
}

galaxy_v36::service::Vector 
galaxy_v36::entities::StarSystem::getPosition() const
{
	return position;
}

int 
galaxy_v36::entities::StarSystem::getSpaceBodiesCount() const
{
	return spaceBodies.size();
}

galaxy_v36::entities::SpaceBody* 
galaxy_v36::entities::StarSystem::getSpaceBody(int index) const
{
	return spaceBodies[index];
}

galaxy_v36::entities::SpaceBody*
galaxy_v36::entities::StarSystem::getSpaceBody(const std::string& name) const
{
	auto spaceBodyIterator = spaceBodiesNamed.find(name);
	if (spaceBodyIterator == spaceBodiesNamed.end())
		return nullptr;

	return spaceBodyIterator->second;
}

galaxy_v36::entities::SpaceBody*
galaxy_v36::entities::StarSystem::getSpaceBody(const service::Vector& position) const
{
	auto spaceBodyIterator = spaceBodiesPositioned.find(position);
	if (spaceBodyIterator == spaceBodiesPositioned.end())
		return nullptr;

	return spaceBodyIterator->second;
}

galaxy_v36::entities::StarSystem::~StarSystem()
{
	for (auto spaceBody : spaceBodies)
		delete spaceBody;
}
