#include <fstream>
#include <iostream>

#include "LibtcodCommandProvider.h"
#include "MovementCommand.h"
#include "Direction.h"

galaxy_v36::game::libtcod::LibtcodCommandProvider::LibtcodCommandProvider()
{
}

void galaxy_v36::game::libtcod::LibtcodCommandProvider::readConfig()
{
    std::ifstream in(getCommandsConfigFileName());

    if (!in)
        return;

    in >> commandProviderConfig;

    in.close();

    for (auto commandConfig : commandProviderConfig["commands"])
    {
        if (commandConfig["type"] == "Movement")
        {
            commands.push_back(new MovementCommand(commandConfig["name"], MovementCommandArguments(service::Direction::get(commandConfig["arguments"]))));
        }
    }
}

std::vector<galaxy_v36::game::Command*>
galaxy_v36::game::libtcod::LibtcodCommandProvider::getCommands()
{
    return commands;
}

std::string galaxy_v36::game::libtcod::LibtcodCommandProvider::getCommandsConfigFileName() const
{
    return "./resources/configs/commands.json";
}
