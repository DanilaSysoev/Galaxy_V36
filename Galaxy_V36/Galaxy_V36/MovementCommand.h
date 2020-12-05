#ifndef MOVEMENT_COMMAND_H
#define MOVEMENT_COMMAND_H

#include "CommonCommand.h"
#include "MovementCommandArguments.h"

namespace galaxy_v36
{
	namespace game
	{
		class MovementCommand : public CommonCommand
		{
		public:
			MovementCommand(const std::string& name, const MovementCommandArguments& arguments);

			virtual const CommandArguments& getArguments() override;


		private:
			MovementCommandArguments arguments;
		};
	}
}


#endif // !MOVEMENT_COMMAND_H

