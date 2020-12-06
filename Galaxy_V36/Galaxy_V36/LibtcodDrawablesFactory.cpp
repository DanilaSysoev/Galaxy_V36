#include <fstream>

#include "LibtcodDrawablesFactory.h"
#include "LibtcodGalaxyDrawable.h"
#include "LibtcodStarSystemDrawable.h"
#include "LibtcodSpaceBodyDrawable.h"
#include "LibtcodCamera.h"

galaxy_v36::LibtcodDrawablesFactory::LibtcodDrawablesFactory()
    : commandHandlers()
{
}

void galaxy_v36::LibtcodDrawablesFactory::prepareBuilding()
{
    std::ifstream in(getDrawablesConfigFileName());

    if (!in)
        return;

    in >> drawablesConfigs;

    in.close();
}

galaxy_v36::game::Camera*
galaxy_v36::LibtcodDrawablesFactory::getGalaxyCamera()
{
    auto camera = new game::libtcod::LibtcodCamera(service::Vector::getZero());
    camera->setOrder(drawablesConfigs[GALAXY_KEYWORD][CAMERA_KEYWORD][HANDLER_ORDER_KEYWORD]);

    commandHandlers[drawablesConfigs[GALAXY_KEYWORD][CAMERA_KEYWORD][HANDLER_TAG_KEYWORD]] = camera;

    return camera;
}

galaxy_v36::game::GalaxyDrawable*
galaxy_v36::LibtcodDrawablesFactory::getGalaxyDrawable(entities::Galaxy* galaxy)
{
    return new game::libtcod::LibtcodGalaxyDrawable(getGalaxyCamera(), galaxy);
}

galaxy_v36::game::Camera*
galaxy_v36::LibtcodDrawablesFactory::getStarSystemCamera()
{
    return nullptr;
}

galaxy_v36::game::StarSystemDrawable*
galaxy_v36::LibtcodDrawablesFactory::getStarSystemDrawable(entities::StarSystem* starSystem)
{
    return new game::libtcod::LibtcodStarSystemDrawable(getStarSystemCamera(), starSystem);
}

galaxy_v36::game::Camera*
galaxy_v36::LibtcodDrawablesFactory::getSpaceBodyCamera()
{
    return nullptr;
}

galaxy_v36::game::SpaceBodyDrawable*
galaxy_v36::LibtcodDrawablesFactory::getSpaceBodyDrawable(entities::SpaceBody* spaceBody, int priority)
{
    return new game::libtcod::LibtcodSpaceBodyDrawable(getSpaceBodyCamera(), spaceBody, priority);
}

galaxy_v36::game::CommandHandler*
galaxy_v36::LibtcodDrawablesFactory::getHandler(const std::string& tag)
{
    if (commandHandlers.find(tag) != commandHandlers.end())
        return commandHandlers[tag];
    return nullptr;
}

std::string
galaxy_v36::LibtcodDrawablesFactory::getDrawablesConfigFileName() const
{
    return "./resources/configs/drawables.json";
}

const std::string
galaxy_v36::LibtcodDrawablesFactory::GALAXY_KEYWORD = "galaxy";
const std::string
galaxy_v36::LibtcodDrawablesFactory::CAMERA_KEYWORD = "camera";
const std::string
galaxy_v36::LibtcodDrawablesFactory::HANDLER_TAG_KEYWORD = "handlerTag";
const std::string
galaxy_v36::LibtcodDrawablesFactory::HANDLER_ORDER_KEYWORD = "handlerOrder";