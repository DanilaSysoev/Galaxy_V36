#include "CommonCommand.h"

galaxy_v36::game::CommonCommand::CommonCommand(const std::string& name)
    : Command(name)
    , handlers()
{
}

void galaxy_v36::game::CommonCommand::addHandler(CommandHandler* handler)
{
    handlers.insert(handler);
}

void galaxy_v36::game::CommonCommand::removeHandler(CommandHandler* handler)
{
    handlers.erase(handler);
}

void galaxy_v36::game::CommonCommand::removeAllHandlers()
{
    handlers.clear();
}

galaxy_v36::game::CommandHandlers& galaxy_v36::game::CommonCommand::getHandlers()
{
    return handlers;
}
