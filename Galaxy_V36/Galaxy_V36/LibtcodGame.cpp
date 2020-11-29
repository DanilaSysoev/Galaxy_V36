#include "LibtcodGame.h"


galaxy_v36::game::libtcod::LibtcodGame::LibtcodGame() 
    : Game(), drawables(), updatables()
{}

galaxy_v36::game::libtcod::LibtcodGame::~LibtcodGame()
{}


void galaxy_v36::game::libtcod::LibtcodGame::prepareGame()
{
}

void galaxy_v36::game::libtcod::LibtcodGame::finishGame()
{
}

bool galaxy_v36::game::libtcod::LibtcodGame::isGameEnd() const
{
    return false;
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
