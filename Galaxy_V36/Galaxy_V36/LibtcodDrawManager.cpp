#include "LibtcodDrawManager.h"
#include "libtcod.hpp"

void 
galaxy_v36::game::libtcod::LibtcodDrawManager::prepareDrawing()
{
	TCODConsole::root->clear();
}

void 
galaxy_v36::game::libtcod::LibtcodDrawManager::flush()
{
	TCODConsole::root->flush();
}
