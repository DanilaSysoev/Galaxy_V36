#include <fstream>

#include "JsonConfig.h"
#include "LibtcodDrawablesFactory.h"
#include "LibtcodGalaxyDrawable.h"
#include "LibtcodStarSystemDrawable.h"
#include "LibtcodSpaceBodyDrawable.h"
#include "LibtcodDrawManager.h"
#include "LibtcodCamera.h"

#include "libtcod.hpp"


using std::string;
using namespace galaxy_v36;
using namespace galaxy_v36::game;
using namespace galaxy_v36::service;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;


LibtcodDrawablesFactory::LibtcodDrawablesFactory()
    : commandHandlers()
{
}

void LibtcodDrawablesFactory::prepareBuilding()
{
    readJson(getDrawablesConfigFileName(), drawablesConfigs);
}

Camera* LibtcodDrawablesFactory::getGalaxyCamera()
{
    auto camera = new LibtcodCamera(Vector::getZero());
    camera->setOrder(
        drawablesConfigs[GALAXY_KEYWORD]
                        [CAMERA_KEYWORD]
                        [HANDLER_ORDER_KEYWORD]
    );    

    auto handlerTag = drawablesConfigs[GALAXY_KEYWORD]
                                      [CAMERA_KEYWORD]
                                      [HANDLER_TAG_KEYWORD];

    commandHandlers[handlerTag] = camera;

    return camera;
}

GalaxyDrawable* LibtcodDrawablesFactory::getGalaxyDrawable(Galaxy* galaxy)
{
    auto galaxyDrawable = new LibtcodGalaxyDrawable(getGalaxyCamera(), galaxy);
    galaxyDrawable->setConsoleName(
        drawablesConfigs[GALAXY_KEYWORD][CONSOLE_KEYWORD]
    );
    return galaxyDrawable;
}

Camera* LibtcodDrawablesFactory::getStarSystemCamera()
{
    return nullptr;
}

StarSystemDrawable* LibtcodDrawablesFactory::getStarSystemDrawable(
    StarSystem* starSystem
)
{
    return new LibtcodStarSystemDrawable(
        getStarSystemCamera(), 
        starSystem
    );
}

Camera* LibtcodDrawablesFactory::getSpaceBodyCamera()
{
    return nullptr;
}

SpaceBodyDrawable* LibtcodDrawablesFactory::getSpaceBodyDrawable(
    SpaceBody* spaceBody, 
    int priority
)
{
    return new LibtcodSpaceBodyDrawable(
        getSpaceBodyCamera(), 
        spaceBody, 
        priority
    );
}

CommandHandler* LibtcodDrawablesFactory::getHandler(const std::string& tag)
{
    if (commandHandlers.find(tag) != commandHandlers.end())
        return commandHandlers[tag];
    return nullptr;
}

string LibtcodDrawablesFactory::getDrawablesConfigFileName()
{
    return "./resources/configs/drawables.json";
}

const string LibtcodDrawablesFactory::GALAXY_KEYWORD = "galaxy";
const string LibtcodDrawablesFactory::CAMERA_KEYWORD = "camera";
const string LibtcodDrawablesFactory::HANDLER_TAG_KEYWORD = "handlerTag";
const string LibtcodDrawablesFactory::HANDLER_ORDER_KEYWORD = "handlerOrder";
const string LibtcodDrawablesFactory::CONSOLE_KEYWORD = "console";