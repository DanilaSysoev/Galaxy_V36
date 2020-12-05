#include "LibtcodCommandProvider.h"

galaxy_v36::game::libtcod::LibtcodCommandProvider::LibtcodCommandProvider()
{
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
