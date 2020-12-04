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
galaxy_v36::game::Command::execute(const CommandArguments& arguments)
{
	for (auto handler : getHandlers())
		handler->execute(arguments);
}

galaxy_v36::game::Command::~Command()
{
}

bool galaxy_v36::game::CommandHandlerComparator::operator()(const CommandHandler* lo, const CommandHandler* ro) const
{
	return lo->getOrder() < ro->getOrder();
}
