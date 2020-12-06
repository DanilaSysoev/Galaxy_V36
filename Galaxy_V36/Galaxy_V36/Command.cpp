#include "Command.h"
#include "CommandHandler.h"

using namespace galaxy_v36::game;


Command::Command(std::string name)
	: name(name)
{
}

std::string Command::getName() const
{
	return name;
}

void Command::execute()
{
	for (auto handler : getHandlers())
		handler->execute(getArguments());
}

Command::~Command()
{
}

bool CommandHandlerComparator::operator()(
	const CommandHandler* lo, 
	const CommandHandler* ro
) const
{
	return lo->getOrder() < ro->getOrder();
}
