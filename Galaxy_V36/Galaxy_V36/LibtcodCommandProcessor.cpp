#include "LibtcodCommandProcessor.h"
#include "Command.h"
#include "LibtcodCamera.h"
#include "CommandProvider.h"
#include "MovementCommandArguments.h"
#include "Direction.h"
#include "libtcod.hpp"

using namespace galaxy_v36::game;
using namespace galaxy_v36::game::libtcod;


LibtcodCommandProcessor::LibtcodCommandProcessor(
	CommandProvider* commandProvider
)
	: commands()
{
	auto commandsTmp = commandProvider->getCommands();

	for(auto command: commandsTmp)
		commands[command->getName()] = command;
}

void LibtcodCommandProcessor::processCommands()
{
	TCOD_key_t key;
	TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr, false);
	if (keyAssigns.find(key.c) != keyAssigns.end())
		keyAssigns[key.c]->execute();
}

void LibtcodCommandProcessor::attachHandler(
	Command* command,
	CommandHandler* handler
)
{
	attachHandler(command->getName(), handler);
}

void LibtcodCommandProcessor::attachHandler(
	const std::string& commandName,
	CommandHandler* handler
)
{
	if (commands.find(commandName) != commands.end())
		commands[commandName]->addHandler(handler);
}

void LibtcodCommandProcessor::removeHandler(
	Command* command, 
	CommandHandler* handler
)
{
	removeHandler(command->getName(), handler);
}

void LibtcodCommandProcessor::removeHandler(
	const std::string& commandName, 
	CommandHandler* handler
)
{
	if (commands.find(commandName) != commands.end())
		commands[commandName]->removeHandler(handler);
}

void LibtcodCommandProcessor::removeAllHandlers(
	const std::string& commandName
)
{
	if (commands.find(commandName) != commands.end())
		commands[commandName]->removeAllHandlers();
}

Command* LibtcodCommandProcessor::getCommand(const std::string& commandName)
{
	if (commands.find(commandName) != commands.end())
		return commands[commandName];
	
	return nullptr;
}

void LibtcodCommandProcessor::assignKey(char key, std::string commandName)
{
	keyAssigns[key] = getCommand(commandName);
}
