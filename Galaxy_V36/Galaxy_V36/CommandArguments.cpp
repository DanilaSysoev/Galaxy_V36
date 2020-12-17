#include "CommandArguments.h"

using namespace galaxy_v36::game;


const CommandArguments& CommandArguments::getEmpty()
{
    return empty;
}

CommandArguments::~CommandArguments()
{
}

const CommandArguments& CommandArguments::empty = CommandArguments();