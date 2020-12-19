#include "LibtcodStarSystemDrawable.h"
#include "LibtcodDrawManager.h"
#include "StarSystem.h"
#include "SpaceBody.h"
#include "Camera.h"
#include "Game.h"

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
    auto console =
        static_cast<LibtcodDrawManager*>(
            Game::getGame()->getDrawManager()
        )->getConsole(getConsoleName());

    for (int i = 0; i < getStarSystem()->getSpaceBodiesCount(); ++i)
    {
        auto spaceBody = getStarSystem()->getSpaceBody(i);
        auto position = spaceBody->getPosition();
        auto screenPosition =
            getCamera()->transformToScreenPosition(position);

        auto image = namedSpaceBodyImages[spaceBody->getType()];
        console->putChar(
            screenPosition.getX(),
            screenPosition.getY(),
            image
        );
    }
}

void LibtcodStarSystemDrawable::initializeImages(
    std::map<std::string, char>& namedSpaceBodyImages
)
{
    LibtcodStarSystemDrawable::namedSpaceBodyImages = namedSpaceBodyImages;
}

const int
LibtcodStarSystemDrawable::STAR_SYSTEM_LIBTCOD_HIGHEST_DRAW_PRIORITY = 100000;

std::map<std::string, char> 
LibtcodStarSystemDrawable::namedSpaceBodyImages;