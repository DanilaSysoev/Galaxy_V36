#include "LibtcodCommandProcessor.h"
#include "libtcod.hpp"


void 
galaxy_v36::game::libtcod::LibtcodCommandProcessor::processCommands()
{
	TCOD_key_t key;
	TCOD_mouse_t mouse;
	TCOD_event_t ev = TCODSystem::waitForEvent(TCOD_EVENT_ANY, &key, &mouse, true);
}
