#include "LibtcodCamera.h"
#include "MovementCommandArguments.h"
#include "Game.h"
#include "CommandProcessor.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::service;
using namespace galaxy_v36::game::libtcod;


LibtcodCamera::LibtcodCamera(const Vector& position)
    : position(position)
    , handlerOrder(0)
{
}

Vector LibtcodCamera::getPosition()
{
    return position;
}

void LibtcodCamera::moveTo(const service::Direction& direction)
{
    position = position.add(direction.getPositionDelta());
}

void LibtcodCamera::execute(const CommandArguments& arguments)
{
    moveTo(
        dynamic_cast<const MovementCommandArguments&>(arguments).getDirection()
    );
}

int LibtcodCamera::getOrder() const
{
    return handlerOrder;
}

void LibtcodCamera::setOrder(int order)
{
    handlerOrder = order;
}
