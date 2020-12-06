#include <fstream>

#include "LibtcodDrawablesFactory.h"
#include "LibtcodGalaxyDrawable.h"
#include "LibtcodStarSystemDrawable.h"
#include "LibtcodSpaceBodyDrawable.h"
#include "LibtcodCamera.h"

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
    std::ifstream in(getDrawablesConfigFileName());

    if (!in)
        return;

    in >> drawablesConfigs;

    in.close();
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
    return new LibtcodGalaxyDrawable(getGalaxyCamera(), galaxy);
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

string LibtcodDrawablesFactory::getDrawablesConfigFileName() const
{
    return "./resources/configs/drawables.json";
}

const string LibtcodDrawablesFactory::GALAXY_KEYWORD = "galaxy";
const string LibtcodDrawablesFactory::CAMERA_KEYWORD = "camera";
const string LibtcodDrawablesFactory::HANDLER_TAG_KEYWORD = "handlerTag";
const string LibtcodDrawablesFactory::HANDLER_ORDER_KEYWORD = "handlerOrder";