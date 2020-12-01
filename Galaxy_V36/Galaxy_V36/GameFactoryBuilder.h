#ifndef GAME_FACTORY_BUILDER_H
#define GAME_FACTORY_BUILDER_H

#include <memory>

#include "GameFactory.h"

namespace galaxy_v36
{
	class GalaxyFactory;

	std::shared_ptr<GameFactory> buildGameFactory(const GameType& gameType, const GalaxyBuildType& galaxyBuildType);
	GalaxyFactory* buildGalaxyFactory(const GalaxyBuildType& galaxyBuildType);
}
#endif // !GAME_FACTORY_BUILDER_H

