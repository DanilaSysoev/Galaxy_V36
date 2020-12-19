#include <map>
#include <string>
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

    buildStarSystemImages();
}

Camera* LibtcodDrawablesFactory::getGalaxyCamera()
{
    if (!galaxyCamera)
        galaxyCamera = buildCamera(
            drawablesConfigs[GALAXY_KEYWORD][CAMERA_KEYWORD]
        );

    return galaxyCamera;
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
    if (!starSystemCamera)
        starSystemCamera = buildCamera(
            drawablesConfigs[STAR_SYSTEM_KEYWORD][CAMERA_KEYWORD]
        );

    return starSystemCamera;
}

StarSystemDrawable* LibtcodDrawablesFactory::getStarSystemDrawable(
    StarSystem* starSystem
)
{
    auto starSystemDrawable = new LibtcodStarSystemDrawable(
        getStarSystemCamera(), 
        starSystem
    );
    starSystemDrawable->setConsoleName(
        drawablesConfigs[STAR_SYSTEM_KEYWORD][CONSOLE_KEYWORD]
    );
    return starSystemDrawable;
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

void galaxy_v36::LibtcodDrawablesFactory::buildStarSystemImages()
{
    std::map<std::string, char> images;

    for (auto image : drawablesConfigs[STAR_SYSTEM_KEYWORD][IMAGES_KEYWORD])
    {
        std::string key = image[0];
        std::string value = image[1];
        images.insert(std::make_pair(key, value[0]));
    }

    LibtcodStarSystemDrawable::initializeImages(images);
}

Camera* LibtcodDrawablesFactory::buildCamera(const nlohmann::json& config)
{
    auto camera = new LibtcodCamera(Vector::getZero());
    camera->setOrder(config[HANDLER_ORDER_KEYWORD]);
    auto handlerTag = config[HANDLER_TAG_KEYWORD];
    commandHandlers[handlerTag] = camera;
    return camera;
}

string LibtcodDrawablesFactory::getDrawablesConfigFileName()
{
    return "./resources/configs/drawables.json";
}

const string LibtcodDrawablesFactory::GALAXY_KEYWORD = "galaxy";
const string LibtcodDrawablesFactory::STAR_SYSTEM_KEYWORD = "starSystem";
const string LibtcodDrawablesFactory::CAMERA_KEYWORD = "camera";
const string LibtcodDrawablesFactory::HANDLER_TAG_KEYWORD = "handlerTag";
const string LibtcodDrawablesFactory::HANDLER_ORDER_KEYWORD = "handlerOrder";
const string LibtcodDrawablesFactory::CONSOLE_KEYWORD = "console";
const string LibtcodDrawablesFactory::IMAGES_KEYWORD = "images";