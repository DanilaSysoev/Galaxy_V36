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
				LibtcodCamera(const service::Vector& position);

				virtual service::Vector getPosition() override;

				virtual void 
					moveTo(const service::Direction& direction) override;

				virtual service::Vector	transformToScreenPosition(
					const service::Vector& worldPosition
				) override;

				virtual int getOrder() const override;

				void setOrder(int order);


			protected:
				virtual void executeProcess(
					const CommandArguments& arguments
				) override;


			private:
				service::Vector position;
				int handlerOrder;
			};
		}
	}
}

#endif // !LIBTCOD_CAMERA_H
