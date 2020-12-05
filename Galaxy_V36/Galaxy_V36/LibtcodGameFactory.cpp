#include <fstream>
#include <map>
#include <string>

#include "LibtcodGameFactory.h"
#include "LibtcodGame.h"
#include "LibtcodDrawManager.h"
#include "LibtcodCommandProcessor.h"
#include "LibtcodCommandProvider.h"
#include "LibtcodUpdateManager.h"
#include "LibtcodGalaxyDrawable.h"
#include "LibtcodDrawablesFactory.h"
#include "LibtcodCamera.h"
#include "DrawablesFactory.h"
#include "GalaxyFactory.h"
#include "Galaxy.h"
#include "Camera.h"


galaxy_v36::LibtcodGameFactory::LibtcodGameFactory(GalaxyFactory* galaxyFactory, DrawablesFactory* drawablesFactory)
    : galaxyFactory(galaxyFactory)
    , drawablesFactory(drawablesFactory)
    , commandLinks()
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

void galaxy_v36::LibtcodGameFactory::prepareBuilding()
{
    readJson(getCommandLinksFileName(), commandLinks);
    readJson(getCommandAssignsFileName(), commandAssigns);
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
    for (auto link : commandLinks["links"])
    {
        auto handler = drawablesFactory->getHandler(link["handlerTag"]);
        if (handler)
            commandProcessor->attachHandler(link["commandName"], handler);
    }

    for (auto assign : commandAssigns["assigns"])
    {
        if (assign["type"] == "keyboard")
        {
            std::string key = assign["key"]; 
            commandProcessor->assignKey(key[0], assign["commandName"]);
        }
    }
}

std::string
galaxy_v36::LibtcodGameFactory::getCommandLinksFileName() const
{
    return "./resources/configs/command_links.json";
}

std::string galaxy_v36::LibtcodGameFactory::getCommandAssignsFileName() const
{
    return "./resources/configs/command_assigns.json";
}

void galaxy_v36::LibtcodGameFactory::readJson(const std::string& filename, nlohmann::json& jsonObject)
{
    std::ifstream in(filename);
    if (!in)
        return;
    in >> jsonObject;
    in.close();
}
