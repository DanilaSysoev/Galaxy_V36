#include "CommonCommand.h"

using namespace galaxy_v36::game;


CommonCommand::CommonCommand(
    const std::string& name,
    const CommonCommandArguments& arguments
)
    : Command(name)
    , handlers()
    , arguments(arguments)
{
}

void CommonCommand::addHandler(CommandHandler* handler)
{
    handlers.insert(handler);
}

void CommonCommand::removeHandler(CommandHandler* handler)
{
    handlers.erase(handler);
}

void CommonCommand::removeAllHandlers()
{
    handlers.clear();
}

CommandHandlers& CommonCommand::getHandlers()
{
    return handlers;
}

const CommandArguments& CommonCommand::getArguments() const
{
    return arguments;
}
