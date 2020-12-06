#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include <string>

namespace galaxy_v36
{
	namespace game
	{
		class Game;
		class Command;
		class CommandHandler;

		class CommandProcessor
		{
		public:
			CommandProcessor();

			virtual void processCommands() = 0;

			virtual void attachHandler(
				Command* command, 
				CommandHandler* handler
			) = 0;
			virtual void attachHandler(
				const std::string& commandName,
				CommandHandler* handler
			) = 0;
			virtual void removeHandler(
				Command* command,
				CommandHandler* handler
			) = 0;
			virtual void removeHandler(
				const std::string& commandName,
				CommandHandler* handler
			) = 0;
			virtual void removeAllHandlers(
				const std::string& commandName
			) = 0;

			virtual Command* getCommand(const std::string& commandName) = 0;

			Game* getGame();
			void setGame(Game* game);

			virtual ~CommandProcessor();


		private:
			Game* game;
		};
	}
}
#endif  // !COMMAND_PROCESSOR_H

