#include "LibtcodGameFactory.h"
#include "LibtcodGame.h"
#include "LibtcodDrawManager.h"
#include "LibtcodCommandProcessor.h"
#include "LibtcodUpdateManager.h"
#include "GalaxyFactory.h"

galaxy_v36::LibtcodGameFactory::LibtcodGameFactory(GalaxyFactory* galaxyFactory)
    : galaxyFactory(galaxyFactory)
{
}

galaxy_v36::LibtcodGameFactory::~LibtcodGameFactory()
{
    delete galaxyFactory;
}

galaxy_v36::game::Game* galaxy_v36::LibtcodGameFactory::buildGame()
{
    return new galaxy_v36::game::libtcod::LibtcodGame(galaxyFactory->buildGalaxy());
}

galaxy_v36::game::UpdateManager* galaxy_v36::LibtcodGameFactory::buildUpdateManager()
{
    return new galaxy_v36::game::libtcod::LibtcodUpdateManager();
}

galaxy_v36::game::DrawManager* galaxy_v36::LibtcodGameFactory::buildDrawManager()
{
    return new galaxy_v36::game::libtcod::LibtcodDrawManager();
}

galaxy_v36::game::CommandProcessor* galaxy_v36::LibtcodGameFactory::buildCommandProcessor()
{
    return new galaxy_v36::game::libtcod::LibtcodCommandProcessor();
}
