#include <exception>

#include "Galaxy.h"
#include "libtcod.hpp"
#include "LibtcodGame.h"
#include "CommonCommandArguments.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;

LibtcodGame::LibtcodGame(Galaxy* galaxy)
    : Game()
    , drawables()
    , updatables()
    , galaxy(galaxy)
    , gameplay(Gameplay::NONE)
    , namedGameplays()
{
    namedGameplays[GALAXY_GAMEPLAY_NAME] = Gameplay::GALAXY_LEVEL;
    namedGameplays[STAR_SYSTEM_GAMEPLAY_NAME] = Gameplay::STAR_SYSTEM_LEVEL;
    namedGameplays[SPACE_BODY_GAMEPLAY_NAME] = Gameplay::SPACE_BODY_LEVEL;

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
    if (this->gameplay == gameplay)
        return;

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
    case Gameplay::NONE:
        break;
    }

    this->gameplay = gameplay;
}

LibtcodGame::Gameplay
LibtcodGame::getGameplayFromString(const std::string& gameplayName)
{
    if (namedGameplays.find(gameplayName) == namedGameplays.end())
        throw std::exception(
            ("incorrect gameplay name: " + gameplayName).c_str()
        );

    return namedGameplays[gameplayName];
}

void LibtcodGame::execute(const CommandArguments& arguments)
{
    auto gameplay = getGameplayFromString(
        dynamic_cast<const CommonCommandArguments&>(arguments).getArgument()
    );

    switchToGameplay(gameplay);
}

int LibtcodGame::getOrder() const
{
    return 0;
}

const std::string LibtcodGame::GALAXY_GAMEPLAY_NAME = "galaxy";
const std::string LibtcodGame::STAR_SYSTEM_GAMEPLAY_NAME = "starSystem";
const std::string LibtcodGame::SPACE_BODY_GAMEPLAY_NAME = "spaceBody";