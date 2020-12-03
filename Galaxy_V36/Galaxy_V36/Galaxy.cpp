#include "StarSystem.h"
#include "Galaxy.h"
#include "LibtcodGalaxyDrawable.h"

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
galaxy_v36::entities::Galaxy::getStarSystemsCount() const
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

galaxy_v36::game::Drawable* 
galaxy_v36::entities::Galaxy::getDrawable()
{
	return drawable;
}

void 
galaxy_v36::entities::Galaxy::setDrawable(game::GalaxyDrawable* drawable)
{
	this->drawable = drawable;
}

galaxy_v36::entities::Galaxy::~Galaxy()
{
	for (auto starSystem : starSystems)
		delete starSystem;

	delete drawable;
}
