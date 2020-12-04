#ifndef LIBTCOD_CAMERA_H
#define LIBTCOD_CAMERA_H

#include "Camera.h"
#include "CommandHandler.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodCamera : public Camera, public CommandHandler
			{
			public:
				LibtcodCamera(service::Vector position = service::Vector::getZero(), int commandHandlerOrder = 0);

				virtual service::Vector getPosition() override;
				virtual void moveTo(const service::Direction& direction) override;
				virtual const std::string& getMotionCommandName() const override;

				virtual void execute(const CommandArguments& arguments) override;
				virtual int getOrder() const override;

				static const std::string LIBTCOD_CAMERA_MOTION_COMMAND_NAME;
			private:
				service::Vector position;
				int handlerOrder;
			};
		}
	}
}

#endif // !LIBTCOD_CAMERA_H
