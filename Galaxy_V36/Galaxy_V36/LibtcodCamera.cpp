#include "LibtcodCamera.h"
#include "MotionCommandArguments.h"
#include "Game.h"
#include "CommandProcessor.h"

galaxy_v36::game::libtcod::LibtcodCamera::LibtcodCamera(service::Vector position, int commandHandlerOrder)
    : position(position)
    , handlerOrder(commandHandlerOrder)
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
    moveTo(dynamic_cast<const MotionCommandArguments&>(arguments).getDirection());
}

int
galaxy_v36::game::libtcod::LibtcodCamera::getOrder() const
{
    return handlerOrder;
}

const std::string&
galaxy_v36::game::libtcod::LibtcodCamera::getMotionCommandName() const
{
    return LIBTCOD_CAMERA_MOTION_COMMAND_NAME;
}

const std::string
galaxy_v36::game::libtcod::LibtcodCamera::LIBTCOD_CAMERA_MOTION_COMMAND_NAME = "CameraMotionCommand";