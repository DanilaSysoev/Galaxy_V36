#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

namespace galaxy_v36
{
	namespace game
	{
		class Game;

		class CommandProcessor
		{
		public:
			virtual void processCommands() = 0;

			Game* getGame();
			void setGame(Game* game);

			virtual ~CommandProcessor();


		private:
			Game* game;
		};
	}
}
#endif  // !COMMAND_PROCESSOR_H

