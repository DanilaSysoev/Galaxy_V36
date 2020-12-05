#include "LibtcodCommandProcessor.h"
#include "Command.h"
#include "LibtcodCamera.h"
#include "CommandProvider.h"
#include "libtcod.hpp"


galaxy_v36::game::libtcod::LibtcodCommandProcessor::LibtcodCommandProcessor(CommandProvider* commandProvider)
	: commands()
{
	auto commandsTmp = commandProvider->getCommands();

	for(auto command: commandsTmp)
		commands[command->getName()] = command;
}

void
galaxy_v36::game::libtcod::LibtcodCommandProcessor::processCommands()
{
	TCOD_key_t key;
	TCOD_mouse_t mouse;
	TCOD_event_t ev = TCODSystem::waitForEvent(TCOD_EVENT_ANY, &key, &mouse, true);
}

void 
galaxy_v36::game::libtcod::LibtcodCommandProcessor::attachHandler(Command* command, CommandHandler* handler)
{
	attachHandler(command->getName(), handler);
}

void 
galaxy_v36::game::libtcod::LibtcodCommandProcessor::attachHandler(const std::string& commandName, CommandHandler* handler)
{
	if (commands.find(commandName) != commands.end())
		commands[commandName]->addHandler(handler);
}

void galaxy_v36::game::libtcod::LibtcodCommandProcessor::removeHandler(Command* command, CommandHandler* handler)
{
	removeHandler(command->getName(), handler);
}

void galaxy_v36::game::libtcod::LibtcodCommandProcessor::removeHandler(const std::string& commandName, CommandHandler* handler)
{
	if (commands.find(commandName) != commands.end())
		commands[commandName]->removeHandler(handler);
}

void galaxy_v36::game::libtcod::LibtcodCommandProcessor::removeAllHandlers(const std::string& commandName)
{
	if (commands.find(commandName) != commands.end())
		commands[commandName]->removeAllHandlers();
}

galaxy_v36::game::Command*
galaxy_v36::game::libtcod::LibtcodCommandProcessor::getCommand(const std::string& commandName)
{
	if (commands.find(commandName) != commands.end())
		return commands[commandName];
	
	return nullptr;
}
