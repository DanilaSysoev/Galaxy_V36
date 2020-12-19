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
			CommandHandler();

			void execute(const CommandArguments& arguments);
			virtual int getOrder() const = 0;
			virtual void disable();
			virtual void enable();
			virtual bool isEnabled();

			virtual ~CommandHandler();


		protected:
			virtual void executeProcess(const CommandArguments& arguments) = 0;


		private:
			bool enabled;
		};
	}
}

#endif // !COMMAND_HANDLER_H
