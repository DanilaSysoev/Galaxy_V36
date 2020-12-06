#include "CommandProcessor.h"

using namespace galaxy_v36::game;


Game* CommandProcessor::getGame()
{
    return game;
}

void CommandProcessor::setGame(Game* game)
{
    this->game = game;
}

CommandProcessor::~CommandProcessor() 
{
}

CommandProcessor::CommandProcessor()
    : game(nullptr)
{
}
