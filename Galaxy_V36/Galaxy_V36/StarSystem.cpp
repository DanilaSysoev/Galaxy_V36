#include <algorithm>

#include "SpaceBody.h"
#include "StarSystem.h"
#include "LibtcodStarSystemDrawable.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::service;
using namespace galaxy_v36::entities;

StarSystem::StarSystem(
	const std::string& name, 
	const Vector& position
)
	: name(name)
	, position(position)
	, spaceBodies()
	, spaceBodiesNamed()
	, spaceBodiesPositioned()
	, drawable(nullptr)
{
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

void StarSystem::addSpaceBody(SpaceBody* spaceBody)
{
	spaceBodies.push_back(spaceBody);
	spaceBodiesNamed[spaceBody->getName()] = spaceBody;
	spaceBodiesPositioned[spaceBody->getPosition()] = spaceBody;
}

void StarSystem::removeSpaceBody(SpaceBody* spacebody)
{
	spaceBodies.erase(
		std::find(spaceBodies.begin(), spaceBodies.end(), spacebody)
	);
	spaceBodiesNamed.erase(spacebody->getName());
	spaceBodiesPositioned.erase(spacebody->getPosition());
}

void StarSystem::removeSpaceBody(const std::string& name)
{
	auto spaceBody = getSpaceBody(name);
	if (spaceBody == nullptr)
		return;

	removeSpaceBody(spaceBody);
}

Drawable* StarSystem::getDrawable()
{
	return drawable;
}

void StarSystem::setDrawable(StarSystemDrawable* drawable)
{
	this->drawable = drawable;
}

StarSystem::~StarSystem()
{
	for (auto spaceBody : spaceBodies)
		delete spaceBody;

	delete drawable;
}
