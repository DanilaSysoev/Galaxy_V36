#include <fstream>
#include <iostream>

#include "LibtcodCommandProvider.h"
#include "MovementCommand.h"
#include "Direction.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::game::libtcod;


LibtcodCommandProvider::LibtcodCommandProvider()
{
}

void LibtcodCommandProvider::readConfig()
{
    std::ifstream in(getCommandsConfigFileName());

    if (!in)
        return;

    in >> commandProviderConfig;

    in.close();

    for (auto commandConfig : commandProviderConfig[COMMANDS_KEYWORD])
    {
        if (commandConfig[TYPE_KEYWORD] == MOVEMENT_TYPE_KEYWORD)
        {
            commands.push_back(
                new MovementCommand(
                    commandConfig[NAME_KEYWORD], 
                    MovementCommandArguments(
                        service::Direction::get(
                            commandConfig[ARGUMENTS_KEYWORD]
                        )
                    )
                )
            );
        }
    }
}

std::vector<Command*> LibtcodCommandProvider::getCommands()
{
    return commands;
}

std::string LibtcodCommandProvider::getCommandsConfigFileName() const
{
    return "./resources/configs/commands.json";
}

const std::string LibtcodCommandProvider::COMMANDS_KEYWORD = "commands";
const std::string LibtcodCommandProvider::NAME_KEYWORD = "name";
const std::string LibtcodCommandProvider::TYPE_KEYWORD = "type";
const std::string LibtcodCommandProvider::ARGUMENTS_KEYWORD = "arguments";

const std::string LibtcodCommandProvider::MOVEMENT_TYPE_KEYWORD = "Movement";