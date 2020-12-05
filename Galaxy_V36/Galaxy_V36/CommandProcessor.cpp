#include "CommandProcessor.h"

galaxy_v36::game::Game*
galaxy_v36::game::CommandProcessor::getGame()
{
    return game;
}

void galaxy_v36::game::CommandProcessor::setGame(Game* game)
{
    this->game = game;
}

galaxy_v36::game::CommandProcessor::~CommandProcessor() 
{
}

galaxy_v36::game::CommandProcessor::CommandProcessor()
    : game(nullptr)
{
}
