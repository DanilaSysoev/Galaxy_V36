#ifndef MOVEMENT_COMMAND_H
#define MOVEMENT_COMMAND_H

#include "Command.h"
#include "MovementCommandArguments.h"

namespace galaxy_v36
{
	namespace game
	{
		class MovementCommand : public Command
		{
		public:
			MovementCommand(
				const std::string& name, 
				const MovementCommandArguments& arguments
			);

			virtual const CommandArguments& getArguments() const override;


		private:
			MovementCommandArguments arguments;
		};
	}
}


#endif // !MOVEMENT_COMMAND_H

