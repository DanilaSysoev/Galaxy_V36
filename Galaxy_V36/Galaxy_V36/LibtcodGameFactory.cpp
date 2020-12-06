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

using namespace galaxy_v36;
using namespace galaxy_v36::game;
using namespace galaxy_v36::libtcod;
using namespace galaxy_v36::service;
using namespace galaxy_v36::entities;


LibtcodGameFactory::LibtcodGameFactory(
    GalaxyFactory* galaxyFactory, 
    DrawablesFactory* drawablesFactory
)
    : galaxyFactory(galaxyFactory)
    , drawablesFactory(drawablesFactory)
    , commandLinks()
    , game(nullptr)
    , updateManager(nullptr)
    , drawManager(nullptr)
    , commandProcessor(nullptr)
{
}

LibtcodGameFactory::~LibtcodGameFactory()
{
    delete galaxyFactory;
    delete drawablesFactory;
}

void LibtcodGameFactory::prepareBuilding()
{
    readJson(getCommandLinksFileName(), commandLinks);
    readJson(getCommandAssignsFileName(), commandAssigns);
}

Game* LibtcodGameFactory::buildGame()
{
    game = new libtcod::LibtcodGame(
        galaxyFactory->buildGalaxy(drawablesFactory)
    );
    return game;
}

UpdateManager* LibtcodGameFactory::buildUpdateManager()
{
    updateManager = new libtcod::LibtcodUpdateManager();
    return updateManager;
}

DrawManager* LibtcodGameFactory::buildDrawManager()
{
    drawManager = new libtcod::LibtcodDrawManager();
    return drawManager;
}

CommandProcessor* LibtcodGameFactory::buildCommandProcessor()
{
    auto commandProvider = new game::libtcod::LibtcodCommandProvider();
    commandProvider->readConfig();
    commandProcessor = new libtcod::LibtcodCommandProcessor(commandProvider);
    delete commandProvider;

    return commandProcessor;
}

void LibtcodGameFactory::linkCommands()
{
    for (auto link : commandLinks[LINKS_KEYWORD])
    {
        auto handler = drawablesFactory->getHandler(link[HANDLER_TAG_KEYWORD]);
        if (handler)
            commandProcessor->attachHandler(
                link[COMMAND_NAME_KEYWORD], 
                handler
            );
    }

    for (auto assign : commandAssigns[ASSIGNS_KEYWORD])
    {
        if (assign[TYPE_KEYWORD] == KEYBOARD_COMMAND_TYPE_KEYWORD)
        {
            std::string key = assign[KEY_KEYWORD]; 
            commandProcessor->assignKey(
                key[0], 
                assign[COMMAND_NAME_KEYWORD]
            );
        }
    }
}

std::string
LibtcodGameFactory::getCommandLinksFileName() const
{
    return "./resources/configs/command_links.json";
}

std::string LibtcodGameFactory::getCommandAssignsFileName() const
{
    return "./resources/configs/command_assigns.json";
}

void LibtcodGameFactory::readJson(
    const std::string& filename, 
    nlohmann::json& jsonObject
)
{
    std::ifstream in(filename);
    if (!in)
        return;
    in >> jsonObject;
    in.close();
}

const std::string LibtcodGameFactory::KEYBOARD_COMMAND_TYPE_KEYWORD = "keyboard";

const std::string LibtcodGameFactory::LINKS_KEYWORD = "links";
const std::string LibtcodGameFactory::ASSIGNS_KEYWORD = "assigns";
const std::string LibtcodGameFactory::COMMAND_NAME_KEYWORD = "commandName";
const std::string LibtcodGameFactory::HANDLER_TAG_KEYWORD = "handlerTag";
const std::string LibtcodGameFactory::TYPE_KEYWORD = "type";
const std::string LibtcodGameFactory::KEY_KEYWORD = "key";