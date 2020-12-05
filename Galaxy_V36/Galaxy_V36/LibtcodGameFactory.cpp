#include "LibtcodGameFactory.h"
#include "LibtcodGame.h"
#include "LibtcodDrawManager.h"
#include "LibtcodCommandProcessor.h"
#include "LibtcodCommandProvider.h"
#include "LibtcodUpdateManager.h"
#include "LibtcodGalaxyDrawable.h"
#include "LibtcodCamera.h"
#include "DrawablesFactory.h"
#include "GalaxyFactory.h"
#include "Galaxy.h"
#include "Camera.h"


galaxy_v36::LibtcodGameFactory::LibtcodGameFactory(GalaxyFactory* galaxyFactory, DrawablesFactory* drawablesFactory)
    : galaxyFactory(galaxyFactory)
    , drawablesFactory(drawablesFactory)
    , game(nullptr)
    , updateManager(nullptr)
    , drawManager(nullptr)
    , commandProcessor(nullptr)
{
}

galaxy_v36::LibtcodGameFactory::~LibtcodGameFactory()
{
    delete galaxyFactory;
    delete drawablesFactory;
}

galaxy_v36::game::Game* galaxy_v36::LibtcodGameFactory::buildGame()
{
    game = new galaxy_v36::game::libtcod::LibtcodGame(galaxyFactory->buildGalaxy(drawablesFactory));
    return game;
}

galaxy_v36::game::UpdateManager* galaxy_v36::LibtcodGameFactory::buildUpdateManager()
{
    updateManager = new galaxy_v36::game::libtcod::LibtcodUpdateManager();
    return updateManager;
}

galaxy_v36::game::DrawManager* galaxy_v36::LibtcodGameFactory::buildDrawManager()
{
    drawManager = new galaxy_v36::game::libtcod::LibtcodDrawManager();
    return drawManager;
}

galaxy_v36::game::CommandProcessor* galaxy_v36::LibtcodGameFactory::buildCommandProcessor()
{
    auto commandProvider = new game::libtcod::LibtcodCommandProvider();
    commandProvider->readConfig();
    commandProcessor = new galaxy_v36::game::libtcod::LibtcodCommandProcessor(commandProvider);
    delete commandProvider;

    return commandProcessor;
}

void galaxy_v36::LibtcodGameFactory::linkCommands()
{
    commandProcessor->attachHandler(
        game->getGalaxy()->getDrawable()->getCamera()->getMotionCommandName(),
        dynamic_cast<game::libtcod::LibtcodCamera*>(game->getGalaxy()->getDrawable()->getCamera())
    );
}
