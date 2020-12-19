#include "CommandHandler.h"

using namespace galaxy_v36::game;


CommandHandler::CommandHandler()
	: enabled(true)
{
}

void CommandHandler::execute(const CommandArguments& arguments)
{
	if (isEnabled())
		executeProcess(arguments);
}

void CommandHandler::disable()
{
	enabled = false;
}

void CommandHandler::enable()
{
	enabled = true;
}

bool CommandHandler::isEnabled()
{
	return enabled;
}

CommandHandler::~CommandHandler()
{
}
