#include "CommonCommand.h"

using namespace galaxy_v36::game;


CommonCommand::CommonCommand(const std::string& name)
    : Command(name)
    , handlers()
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
