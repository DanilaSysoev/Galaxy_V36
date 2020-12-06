#include "LibtcodDrawManager.h"
#include "libtcod.hpp"

using namespace galaxy_v36::game;
using namespace galaxy_v36::game::libtcod;

void LibtcodDrawManager::prepareDrawing()
{
	TCODConsole::root->clear();
}

void LibtcodDrawManager::flush()
{
	TCODConsole::root->flush();
}
