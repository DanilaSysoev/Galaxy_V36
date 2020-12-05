#ifndef COMMAND_PROVIDER_H
#define COMMAND_PROVIDER_H

#include <vector>

namespace galaxy_v36
{
	namespace game
	{
		class Command;

		class CommandProvider
		{
		public:
			virtual std::vector<Command*> getCommands() = 0;

			virtual ~CommandProvider();
		};
	}
}

#endif // !COMMAND_PROVIDER_H

