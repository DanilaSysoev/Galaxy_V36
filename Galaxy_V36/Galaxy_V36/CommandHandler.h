#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

namespace galaxy_v36
{
	namespace game
	{
		class Command;
		class CommandArguments;

		class CommandHandler
		{
		public:
			virtual void execute(Command* command, CommandArguments* arguments) = 0;

			virtual int getOrder() const = 0;

			virtual ~CommandHandler();

		};
	}
}

#endif // !COMMAND_HANDLER_H
