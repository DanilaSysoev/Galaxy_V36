#ifndef LIBTCOD_COMMAND_PROCESSOR_H
#define LIBTCOD_COMMAND_PROCESSOR_H

#include <string>
#include <map>

#include "CommandProcessor.h"

namespace galaxy_v36
{
	namespace game
	{
		using Commands = std::map<std::string, Command*>;

		namespace libtcod
		{
			class LibtcodCommandProcessor : public CommandProcessor
			{
			public:

				virtual void processCommands()                                                      override;
				virtual void attachHandler(Command* command, CommandHandler* handler)               override;
				virtual void attachHandler(const std::string& commandName, CommandHandler* handler) override;
				virtual void removeHandler(Command* command, CommandHandler* handler)               override;
				virtual void removeHandler(const std::string& commandName, CommandHandler* handler) override;
				virtual void removeAllHandlers(const std::string& commandName)                      override;
				virtual Command* getCommand(const std::string& commandName)                         override;


			private:
				Commands commands;
			};
		}
	}
}

#endif  // !LIBTCOD_COMMAND_PROCESSOR_H
