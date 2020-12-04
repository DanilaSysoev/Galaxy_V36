#ifndef MOTION_COMMAND_ARGUMENTS_H
#define MOTION_COMMAND_ARGUMENTS_H

#include "CommandArguments.h"

namespace galaxy_v36
{
	namespace service
	{
		class Direction;
	}
	namespace game
	{
		class MotionCommandArguments : public CommandArguments
		{
		public:
			MotionCommandArguments(service::Direction& direction);

			const service::Direction& getDirection() const;

		private:
			const service::Direction& direction;
		};
	}
}

#endif // !MOTION_COMMAND_ARGUMENTS_H

