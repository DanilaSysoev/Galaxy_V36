#include "Command.h"
#include "CommandHandler.h"

galaxy_v36::game::Command::Command(std::string name)
	: name(name)
{
}

std::string 
galaxy_v36::game::Command::getName() const
{
	return name;
}

void
galaxy_v36::game::Command::execute()
{
	for (auto handler : getHandlers())
		handler->execute(getArguments());
}

galaxy_v36::game::Command::~Command()
{
}

bool galaxy_v36::game::CommandHandlerComparator::operator()(const CommandHandler* lo, const CommandHandler* ro) const
{
	return lo->getOrder() < ro->getOrder();
}
