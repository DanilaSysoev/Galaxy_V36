#ifndef DUMMY_COMMAND_PROVIDER
#define DUMMY_COMMAND_PROVIDER

#include <string>

#include "CommandProvider.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodCommandProvider : public CommandProvider
			{
			public:
				LibtcodCommandProvider();

				virtual std::vector<Command*> getCommands() override;


			private:
				std::vector<Command*> commands;
				std::string getCommandsConfigFileName() const;
			};
		}
	}
}

#endif // !DUMMY_COMMAND_PROVIDER
