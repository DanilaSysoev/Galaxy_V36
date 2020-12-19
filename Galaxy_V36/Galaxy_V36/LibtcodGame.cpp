#include <exception>

#include "Galaxy.h"
#include "libtcod.hpp"
#include "StarSystem.h"
#include "LibtcodGame.h"
#include "LibtcodGameplay.h"
#include "CommonCommandArguments.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;
using namespace galaxy_v36::game::libtcod;

LibtcodGame::LibtcodGame(
    Galaxy* galaxy,
    const std::vector<LibtcodGameplay*>& gameplays,
    const std::string& startGameplayName,
    const std::vector<Drawable*>& baseDrawables
)
    : Game()
    , drawables()
    , updatables()
    , galaxy(galaxy)
    , gameplay(nullptr)
    , namedGameplays()
    , baseDrawables(baseDrawables)
{
    for (auto gp : gameplays)
        namedGameplays.insert(std::make_pair(gp->getName(), gp));

    switchToGameplay(startGameplayName);
}

LibtcodGame::~LibtcodGame()
{
    if (galaxy != nullptr)
        delete galaxy;

    for (auto gp : namedGameplays)
        delete gp.second;
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

void LibtcodGame::executeProcess(const CommandArguments& arguments)
{
    auto gameplayName =
        dynamic_cast<const CommonCommandArguments&>(arguments).getArgument();

    switchToGameplay(gameplayName);
}

void LibtcodGame::switchToGameplay(const std::string& gameplayName)
{
    if (gameplay)
    {
        gameplay->deactivate();
    }

    drawables.clear();

    gameplay = namedGameplays[gameplayName];
    gameplay->activate();

    drawables.insert(baseDrawables.begin(), baseDrawables.end());
    drawables.insert(gameplay->getDrawables().begin(), gameplay->getDrawables().end());
}

int LibtcodGame::getOrder() const
{
    return 0;
}

LibtcodGameplay* LibtcodGame::getGameplay(std::string name)
{
    auto gameplay = namedGameplays.find(name);
    if (gameplay != namedGameplays.end())
        return gameplay->second;
    return nullptr;
}
