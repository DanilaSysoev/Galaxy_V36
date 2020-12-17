#include <fstream>
#include <iostream>

#include "JsonConfig.h"
#include "LibtcodCommandProvider.h"
#include "CommonCommand.h"
#include "Direction.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::service;
using namespace galaxy_v36::game::libtcod;


LibtcodCommandProvider::LibtcodCommandProvider()
{
}

void LibtcodCommandProvider::readConfig()
{
    readJson(getCommandsConfigFileName(), commandProviderConfig);

    for (auto commandConfig : commandProviderConfig[COMMANDS_KEYWORD])
    {
        commands.push_back(
            new CommonCommand(
                commandConfig[NAME_KEYWORD],
                CommonCommandArguments(
                    commandConfig[ARGUMENTS_KEYWORD]
                )
            )
        );
    }
}

std::vector<Command*> LibtcodCommandProvider::getCommands()
{
    return commands;
}

std::string LibtcodCommandProvider::getCommandsConfigFileName()
{
    return "./resources/configs/commands.json";
}

const std::string LibtcodCommandProvider::COMMANDS_KEYWORD = "commands";
const std::string LibtcodCommandProvider::NAME_KEYWORD = "name";
const std::string LibtcodCommandProvider::ARGUMENTS_KEYWORD = "arguments";