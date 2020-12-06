#include "LibtcodStarSystemDrawable.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;

LibtcodStarSystemDrawable::LibtcodStarSystemDrawable(
    Camera* camera, 
    StarSystem* starSystem
)
    : StarSystemDrawable(camera, starSystem)
{
}

int LibtcodStarSystemDrawable::getDrawPriority() const
{
    return STAR_SYSTEM_LIBTCOD_HIGHEST_DRAW_PRIORITY;
}

void LibtcodStarSystemDrawable::draw()
{
    // TODO
}

const int
LibtcodStarSystemDrawable::STAR_SYSTEM_LIBTCOD_HIGHEST_DRAW_PRIORITY = 100000;