#include "GameFactoryBuilder.h"
#include "LibtcodGameFactory.h"
#include "DummyGalaxyFactory.h"
#include "GalaxyFactory.h"

std::shared_ptr<galaxy_v36::GameFactory>
galaxy_v36::buildGameFactory(const galaxy_v36::GameType& gameType, const GalaxyBuildType& galaxyBuildType)
{
	switch (gameType)
	{
	case GameType::LIBTCOD:
		return std::make_shared<LibtcodGameFactory>(buildGalaxyFactory(galaxyBuildType));
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