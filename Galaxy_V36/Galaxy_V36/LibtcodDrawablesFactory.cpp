#include <fstream>

#include "LibtcodDrawablesFactory.h"
#include "LibtcodGalaxyDrawable.h"
#include "LibtcodStarSystemDrawable.h"
#include "LibtcodSpaceBodyDrawable.h"
#include "LibtcodCamera.h"

void galaxy_v36::LibtcodDrawablesFactory::readConfig()
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
    auto camera = new game::libtcod::LibtcodCamera(
        service::Vector::getZero(), 
        drawablesConfigs["galaxy"]["cameraMovemetCommand"], 
        drawablesConfigs["galaxy"]["cameraMovemetHandlerOrder"]
    );

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

std::string galaxy_v36::LibtcodDrawablesFactory::getDrawablesConfigFileName() const
{
    return "./resources/configs/drawables.json";
}
