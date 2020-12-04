#include "MotionCommandArguments.h"

galaxy_v36::game::MotionCommandArguments::MotionCommandArguments(service::Direction& direction)
    : direction(direction)
{
}

const galaxy_v36::service::Direction&
galaxy_v36::game::MotionCommandArguments::getDirection() const
{
    return direction;
}
