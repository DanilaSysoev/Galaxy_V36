#include "LibtcodCamera.h"
#include "MovementCommandArguments.h"
#include "Game.h"
#include "CommandProcessor.h"

galaxy_v36::game::libtcod::LibtcodCamera::LibtcodCamera(const service::Vector& position)
    : position(position)
    , handlerOrder(0)
{
}

galaxy_v36::service::Vector
galaxy_v36::game::libtcod::LibtcodCamera::getPosition()
{
    return position;
}

void
galaxy_v36::game::libtcod::LibtcodCamera::moveTo(const service::Direction& direction)
{
    position = position.add(direction.getPositionDelta());
}

void
galaxy_v36::game::libtcod::LibtcodCamera::execute(const CommandArguments& arguments)
{
    moveTo(dynamic_cast<const MovementCommandArguments&>(arguments).getDirection());
}

int
galaxy_v36::game::libtcod::LibtcodCamera::getOrder() const
{
    return handlerOrder;
}

void galaxy_v36::game::libtcod::LibtcodCamera::setOrder(int order)
{
    handlerOrder = order;
}
