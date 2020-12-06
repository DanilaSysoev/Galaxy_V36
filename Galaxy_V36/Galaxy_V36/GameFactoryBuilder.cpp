#include "GameFactoryBuilder.h"
#include "LibtcodGameFactory.h"
#include "DummyGalaxyFactory.h"
#include "GalaxyFactory.h"
#include "LibtcodDrawablesFactory.h"

using std::string;
using namespace galaxy_v36;
using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;


std::shared_ptr<GameFactory> galaxy_v36::buildGameFactory(
	const GameType& gameType, 
	const GalaxyBuildType& galaxyBuildType,
	const DrawablesType& drawablesType
)
{
	switch (gameType)
	{
	case GameType::LIBTCOD:
		return std::make_shared<LibtcodGameFactory>(
			galaxy_v36::buildGalaxyFactory(galaxyBuildType),
			galaxy_v36::buildDrawablesFactory(drawablesType));
	}

	return nullptr;
}

GalaxyFactory* galaxy_v36::buildGalaxyFactory(
	const GalaxyBuildType& galaxyBuildType
)
{
	switch (galaxyBuildType)
	{
	case GalaxyBuildType::DUMMY:
		return new DummyGalaxyFactory();
	}

	return nullptr;
}

DrawablesFactory* galaxy_v36::buildDrawablesFactory(
	const DrawablesType& drawablesType
)
{
	switch (drawablesType)
	{
	case DrawablesType::LIBTCOD:
		auto drawablesFactory = new LibtcodDrawablesFactory();
		drawablesFactory->prepareBuilding();
		return drawablesFactory;
	}

	return nullptr;
}
