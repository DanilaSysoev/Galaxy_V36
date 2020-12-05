#include "MovementCommandArguments.h"

galaxy_v36::game::MovementCommandArguments::MovementCommandArguments(const service::Direction& direction)
    : direction(direction)
{
}

const galaxy_v36::service::Direction&
galaxy_v36::game::MovementCommandArguments::getDirection() const
{
    return direction;
}
