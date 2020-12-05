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
		class MovementCommandArguments : public CommandArguments
		{
		public:
			MovementCommandArguments(const service::Direction& direction);

			const service::Direction& getDirection() const;

		private:
			const service::Direction& direction;
		};
	}
}

#endif // !MOTION_COMMAND_ARGUMENTS_H

