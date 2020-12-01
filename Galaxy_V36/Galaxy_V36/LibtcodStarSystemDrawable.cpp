#include "LibtcodStarSystemDrawable.h"

int
galaxy_v36::game::libtcod::LibtcodStarSystemDrawable::getDrawPriority() const
{
    return STAR_SYSTEM_LIBTCOD_HIGHEST_DRAW_PRIORITY;
}

void
galaxy_v36::game::libtcod::LibtcodStarSystemDrawable::draw()
{
    // TODO
}

const int galaxy_v36::game::libtcod::LibtcodStarSystemDrawable::STAR_SYSTEM_LIBTCOD_HIGHEST_DRAW_PRIORITY = 100000;