#include "StarSystem.h"
#include "Galaxy.h"

galaxy_v36::entities::Galaxy::Galaxy(std::vector<StarSystem*> starSystems)
	: starSystems(starSystems)
	, starSystemsNamed()
	, starSystemsPositioned()
{
	for (auto starSystem : starSystems) {
		starSystemsNamed[starSystem->getName()] = starSystem;
		starSystemsPositioned[starSystem->getPosition()] = starSystem;
	}
}

int
galaxy_v36::entities::Galaxy::gaeStarSystemsCount() const
{
	return starSystems.size();
}

galaxy_v36::entities::StarSystem*
galaxy_v36::entities::Galaxy::getStarSystem(int index) const
{
	return starSystems[index];
}

galaxy_v36::entities::StarSystem*
galaxy_v36::entities::Galaxy::getStarSystem(const std::string& name) const
{
	auto starSystemIterator = starSystemsNamed.find(name);
	if (starSystemIterator == starSystemsNamed.end())
		return nullptr;

	return starSystemIterator->second;
}

galaxy_v36::entities::StarSystem*
galaxy_v36::entities::Galaxy::getStarSystem(const service::Vector& position) const
{
	auto starSystemIterator = starSystemsPositioned.find(position);
	if (starSystemIterator == starSystemsPositioned.end())
		return nullptr;

	return starSystemIterator->second;
}

galaxy_v36::entities::Galaxy::~Galaxy()
{
	for (auto starSystem : starSystems)
		delete starSystem;
}
