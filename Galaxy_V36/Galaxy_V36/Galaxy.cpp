#include "StarSystem.h"
#include "Galaxy.h"
#include "LibtcodGalaxyDrawable.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;

Galaxy::Galaxy(std::vector<StarSystem*> starSystems)
	: starSystems(starSystems)
	, starSystemsNamed()
	, starSystemsPositioned()
	, drawable(nullptr)
{
	for (auto starSystem : starSystems) {
		starSystemsNamed[starSystem->getName()] = starSystem;
		starSystemsPositioned[starSystem->getPosition()] = starSystem;
	}
}

int Galaxy::getStarSystemsCount() const
{
	return starSystems.size();
}

StarSystem* Galaxy::getStarSystem(int index) const
{
	return starSystems[index];
}

StarSystem* Galaxy::getStarSystem(const std::string& name) const
{
	auto starSystemIterator = starSystemsNamed.find(name);
	if (starSystemIterator == starSystemsNamed.end())
		return nullptr;

	return starSystemIterator->second;
}

StarSystem* Galaxy::getStarSystem(const service::Vector& position) const
{
	auto starSystemIterator = starSystemsPositioned.find(position);
	if (starSystemIterator == starSystemsPositioned.end())
		return nullptr;

	return starSystemIterator->second;
}

Drawable* Galaxy::getDrawable()
{
	return drawable;
}

void Galaxy::setDrawable(game::GalaxyDrawable* drawable)
{
	this->drawable = drawable;
}

Galaxy::~Galaxy()
{
	for (auto starSystem : starSystems)
		delete starSystem;

	delete drawable;
}
