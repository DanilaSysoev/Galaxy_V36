#include "LibtcodGame.h"
#include "Galaxy.h"
#include "libtcod.hpp"


galaxy_v36::game::libtcod::LibtcodGame::LibtcodGame(entities::Galaxy* galaxy)
    : Game()
    , drawables()
    , updatables()
    , galaxy(galaxy)
    , gameplay(Gameplay::GALAXY_LEVEL)
{
    switchToGameplay(Gameplay::GALAXY_LEVEL);
}

galaxy_v36::game::libtcod::LibtcodGame::~LibtcodGame()
{
    if (galaxy != nullptr)
        delete galaxy;
}


void 
galaxy_v36::game::libtcod::LibtcodGame::prepareGame()
{
    TCODConsole::initRoot(128, 64, "Galaxy V64");
    TCODSystem::setFps(60);
}

void galaxy_v36::game::libtcod::LibtcodGame::finishGame()
{
}

bool 
galaxy_v36::game::libtcod::LibtcodGame::isGameEnd() const
{
    return TCODConsole::root->isWindowClosed();
}


galaxy_v36::game::Drawables& 
galaxy_v36::game::libtcod::LibtcodGame::getDravables()
{
    return drawables;
}

galaxy_v36::game::Updatables& 
galaxy_v36::game::libtcod::LibtcodGame::getUpdatables()
{
    return updatables;
}

galaxy_v36::entities::Galaxy*
galaxy_v36::game::libtcod::LibtcodGame::getGalaxy()
{
    return galaxy;
}

void
galaxy_v36::game::libtcod::LibtcodGame::switchToGameplay(const Gameplay& gameplay)
{
    switch (gameplay)
    {
    case Gameplay::GALAXY_LEVEL: 
        drawables.clear();
        drawables.insert(galaxy->getDrawable());
        break;
    case Gameplay::STAR_SYSTEM_LEVEL:
        break;
    case Gameplay::SPACE_BODY_LEVEL:
        break;
    }
}
