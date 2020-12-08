#include "LibtcodGame.h"
#include "Galaxy.h"
#include "libtcod.hpp"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;

LibtcodGame::LibtcodGame(Galaxy* galaxy)
    : Game()
    , drawables()
    , updatables()
    , galaxy(galaxy)
    , gameplay(Gameplay::GALAXY_LEVEL)
{
    switchToGameplay(Gameplay::GALAXY_LEVEL);
}

LibtcodGame::~LibtcodGame()
{
    if (galaxy != nullptr)
        delete galaxy;
}


void LibtcodGame::prepareGame()
{
    TCODSystem::setFps(60);
}

void LibtcodGame::finishGame()
{
}

bool LibtcodGame::isGameEnd() const
{
    return TCODConsole::root->isWindowClosed();
}


Drawables& LibtcodGame::getDravables()
{
    return drawables;
}

Updatables& LibtcodGame::getUpdatables()
{
    return updatables;
}

Galaxy* LibtcodGame::getGalaxy()
{
    return galaxy;
}

void LibtcodGame::switchToGameplay(const Gameplay& gameplay)
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
