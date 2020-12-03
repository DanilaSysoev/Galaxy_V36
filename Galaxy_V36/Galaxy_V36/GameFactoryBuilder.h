#ifndef GAME_FACTORY_BUILDER_H
#define GAME_FACTORY_BUILDER_H

#include <memory>

#include "GameFactory.h"
#include "GalaxyBuildType.h"
#include "DrawablesType.h"


namespace galaxy_v36
{
	class GalaxyFactory;
	class DrawablesFactory;

	std::shared_ptr<GameFactory> buildGameFactory(
		const GameType& gameType, 
		const GalaxyBuildType& galaxyBuildType,
		const DrawablesType& drawablesType);

	GalaxyFactory* buildGalaxyFactory(const GalaxyBuildType& galaxyBuildType);
	DrawablesFactory* buildDrawablesFactory(const DrawablesType& drawablesType);
}

#endif // !GAME_FACTORY_BUILDER_H

