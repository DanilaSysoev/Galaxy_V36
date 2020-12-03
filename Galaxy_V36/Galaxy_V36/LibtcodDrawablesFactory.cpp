#include "LibtcodDrawablesFactory.h"
#include "LibtcodGalaxyDrawable.h"
#include "LibtcodStarSystemDrawable.h"
#include "LibtcodSpaceBodyDrawable.h"

galaxy_v36::game::GalaxyDrawable* 
galaxy_v36::LibtcodDrawablesFactory::getGalaxyDrawable(entities::Galaxy* galaxy)
{
    return new game::libtcod::LibtcodGalaxyDrawable(galaxy);
}

galaxy_v36::game::StarSystemDrawable*
galaxy_v36::LibtcodDrawablesFactory::getStarSystemDrawable(entities::StarSystem* starSystem)
{
    return new game::libtcod::LibtcodStarSystemDrawable(starSystem);
}

galaxy_v36::game::SpaceBodyDrawable*
galaxy_v36::LibtcodDrawablesFactory::getSpaceBodyDrawable(entities::SpaceBody* spaceBody, int priority)
{
    return new game::libtcod::LibtcodSpaceBodyDrawable(spaceBody, priority);
}
