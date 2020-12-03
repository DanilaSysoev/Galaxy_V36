#include "GameFactoryBuilder.h"
#include "LibtcodGameFactory.h"
#include "DummyGalaxyFactory.h"
#include "GalaxyFactory.h"
#include "LibtcodDrawablesFactory.h"

std::shared_ptr<galaxy_v36::GameFactory>
galaxy_v36::buildGameFactory(
	const galaxy_v36::GameType& gameType, 
	const GalaxyBuildType& galaxyBuildType,
	const DrawablesType& drawablesType)
{
	switch (gameType)
	{
	case GameType::LIBTCOD:
		return std::make_shared<LibtcodGameFactory>(
			buildGalaxyFactory(galaxyBuildType),
			buildDrawablesFactory(drawablesType));
	}

	return nullptr;
}

galaxy_v36::GalaxyFactory*
galaxy_v36::buildGalaxyFactory(const GalaxyBuildType& galaxyBuildType)
{
	switch (galaxyBuildType)
	{
	case GalaxyBuildType::DUMMY:
		return new DummyGalaxyFactory();
	}

	return nullptr;
}

galaxy_v36::DrawablesFactory* galaxy_v36::buildDrawablesFactory(const DrawablesType& drawablesType)
{
	switch (drawablesType)
	{
	case DrawablesType::LIBTCOD:
		return new galaxy_v36::LibtcodDrawablesFactory();
	}

	return nullptr;
}
