#include <fstream>
#include <iostream>

#include "LibtcodCommandProvider.h"
#include "CommonCommand.h" 

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
        if (commandConfig["type"] == "Common")
        {
            commands.push_back(new CommonCommand(commandConfig["name"]));
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
