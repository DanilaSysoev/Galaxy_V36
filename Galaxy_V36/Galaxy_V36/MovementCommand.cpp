#include "MovementCommand.h"

using namespace galaxy_v36::game;


MovementCommand::MovementCommand(
    const std::string& name,
    const MovementCommandArguments& arguments
)
    : CommonCommand(name)
    , arguments(arguments)
{
}

const CommandArguments& MovementCommand::getArguments()
{
    return arguments;
}
