#include "MovementCommandArguments.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::service;


MovementCommandArguments::MovementCommandArguments(
    const Direction& direction
)
    : direction(direction)
{
}

const Direction& MovementCommandArguments::getDirection() const
{
    return direction;
}
