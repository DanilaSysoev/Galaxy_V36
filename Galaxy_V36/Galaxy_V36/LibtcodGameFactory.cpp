#include <fstream>
#include <map>
#include <string>

#include "JsonConfig.h"
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
#include "CommandHandler.h"

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
    , commandLinksConfigs()
    , game(nullptr)
    , updateManager(nullptr)
    , drawManager(nullptr)
    , commandProcessor(nullptr)
    , commandHandlers()
{
}

CommandHandler* LibtcodGameFactory::getHandler(const std::string& tag)
{
    if (commandHandlers.find(tag) != commandHandlers.end())
        return commandHandlers[tag];
    return drawablesFactory->getHandler(tag);
}

LibtcodGameFactory::~LibtcodGameFactory()
{
    delete galaxyFactory;
    delete drawablesFactory;
}

void LibtcodGameFactory::prepareBuilding()
{
    readJson(getCommandLinksFileName(), commandLinksConfigs);
    readJson(getCommandAssignsFileName(), commandAssignsConfigs);
    readJson(getConsolesFileName(), consolesConfigs);
    readJson(getGameFileName(), gameConfigs);
}

Game* LibtcodGameFactory::buildGame()
{
    game = new libtcod::LibtcodGame(
        galaxyFactory->buildGalaxy(drawablesFactory)
    );

    commandHandlers[
        gameConfigs[GAME_KEYWORD][HANDLER_TAG_KEYWORD]
    ] = game;

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

void LibtcodGameFactory::postprocess()
{
    linkCommands();
    assignKeys();
    setupConsoles();
}

std::string
LibtcodGameFactory::getCommandLinksFileName()
{
    return "./resources/configs/command_links.json";
}

std::string LibtcodGameFactory::getCommandAssignsFileName()
{
    return "./resources/configs/command_assigns.json";
}

std::string galaxy_v36::LibtcodGameFactory::getConsolesFileName()
{
    return "./resources/configs/consoles.json";
}

std::string galaxy_v36::LibtcodGameFactory::getGameFileName()
{
    return "./resources/configs/game.json";
}

void LibtcodGameFactory::linkCommands()
{
    for (auto link : commandLinksConfigs[LINKS_KEYWORD])
    {
        auto handler = getHandler(link[HANDLER_TAG_KEYWORD]);
        if (handler)
            commandProcessor->attachHandler(
                link[COMMAND_NAME_KEYWORD],
                handler
            );
    }
}

void LibtcodGameFactory::assignKeys()
{
    for (auto assign : commandAssignsConfigs[ASSIGNS_KEYWORD])
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

void LibtcodGameFactory::setupConsoles()
{
    for (auto consoleConfig : consolesConfigs[CONSOLES_KEYWORD])
    {
        std::string name = consoleConfig[NAME_KEYWORD];
        if (name == ROOT_CONSOLE_NAME)
            setupRoot(consoleConfig);
        else
            setupConsole(consoleConfig);
    }
}

void LibtcodGameFactory::setupRoot(const nlohmann::json& consoleConfig)
{
    std::string name = consoleConfig[NAME_KEYWORD];
    int width = consoleConfig[WIDTH_KEYWORD];
    int height = consoleConfig[HEIGHT_KEYWORD];
    TCODColor background = parseColor(consoleConfig[BACKGROUND_KEYWORD]);
    TCODColor foreground = parseColor(consoleConfig[FOREGROUND_KEYWORD]);

    std::string title = consoleConfig[TITLE_KEYWORD];
    TCODConsole::initRoot(width, height, title.c_str());
    auto console = TCODConsole::root;
    
    console->setDefaultBackground(background);
    console->setDefaultForeground(foreground);
    
    drawManager->addConsole(name, console);
}

void LibtcodGameFactory::setupConsole(const nlohmann::json& consoleConfig)
{
    std::string name = consoleConfig[NAME_KEYWORD];
    int width = consoleConfig[WIDTH_KEYWORD];
    int height = consoleConfig[HEIGHT_KEYWORD];
    TCODColor background = parseColor(consoleConfig[BACKGROUND_KEYWORD]);
    TCODColor foreground = parseColor(consoleConfig[FOREGROUND_KEYWORD]);

    auto console = new TCODConsole(width, height);

    console->setDefaultBackground(background);
    console->setDefaultForeground(foreground);
    if (consoleConfig.contains(PARENT_KEYWORD))
    {
        Vector position = Vector(
            consoleConfig[X_KEYWORD],
            consoleConfig[Y_KEYWORD]
        );
        std::string parent = consoleConfig[PARENT_KEYWORD];
        drawManager->addConsole(name, console, position, parent);
    }
    else
        drawManager->addConsole(name, console);
}

TCODColor LibtcodGameFactory::parseColor(const nlohmann::json& consoleConfig)
{
    return TCODColor(
        static_cast<int>(consoleConfig[0]),
        static_cast<int>(consoleConfig[1]),
        static_cast<int>(consoleConfig[2])
    );
}

const std::string LibtcodGameFactory::KEYBOARD_COMMAND_TYPE_KEYWORD = "keyboard";

const std::string LibtcodGameFactory::GAME_KEYWORD = "game";

const std::string LibtcodGameFactory::LINKS_KEYWORD = "links";
const std::string LibtcodGameFactory::ASSIGNS_KEYWORD = "assigns";
const std::string LibtcodGameFactory::COMMAND_NAME_KEYWORD = "commandName";
const std::string LibtcodGameFactory::HANDLER_TAG_KEYWORD = "handlerTag";
const std::string LibtcodGameFactory::TYPE_KEYWORD = "type";
const std::string LibtcodGameFactory::KEY_KEYWORD = "key";

const std::string LibtcodGameFactory::WIDTH_KEYWORD = "width";
const std::string LibtcodGameFactory::HEIGHT_KEYWORD = "height";
const std::string LibtcodGameFactory::X_KEYWORD = "x";
const std::string LibtcodGameFactory::Y_KEYWORD = "y";
const std::string LibtcodGameFactory::BACKGROUND_KEYWORD = "background";
const std::string LibtcodGameFactory::FOREGROUND_KEYWORD = "foreground";
const std::string LibtcodGameFactory::CONSOLES_KEYWORD = "consoles";
const std::string LibtcodGameFactory::NAME_KEYWORD = "name";
const std::string LibtcodGameFactory::PARENT_KEYWORD = "parent";
const std::string LibtcodGameFactory::TITLE_KEYWORD = "title";

const std::string LibtcodGameFactory::ROOT_CONSOLE_NAME = "root";