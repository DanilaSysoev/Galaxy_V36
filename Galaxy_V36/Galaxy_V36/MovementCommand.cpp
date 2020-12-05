#include "MovementCommand.h"

galaxy_v36::game::MovementCommand::MovementCommand(const std::string& name, const MovementCommandArguments& arguments)
    : CommonCommand(name)
    , arguments(arguments)
{
}

const galaxy_v36::game::CommandArguments& galaxy_v36::game::MovementCommand::getArguments()
{
    return arguments;
}
