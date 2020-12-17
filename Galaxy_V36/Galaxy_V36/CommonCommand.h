#ifndef COMMON_COMMAND_H
#define COMMON_COMMAND_H

#include "Command.h"
#include "CommonCommandArguments.h"

namespace galaxy_v36
{
	namespace game
	{
		class CommonCommand : public Command
		{
		public:
			CommonCommand(
				const std::string& name, 
				const CommonCommandArguments& arguments
			);

			virtual void addHandler(CommandHandler* handler) override;
			virtual void removeHandler(CommandHandler* handler) override;
			virtual void removeAllHandlers() override;
			virtual const CommandArguments& getArguments() const;


		protected:
			virtual CommandHandlers& getHandlers() override;


		private:
			CommonCommandArguments arguments;

			CommandHandlers handlers;
		};
	}
}

#endif // !COMMON_COMMAND_H

