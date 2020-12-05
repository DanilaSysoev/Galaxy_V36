#ifndef COMMON_COMMAND_H
#define COMMON_COMMAND_H

#include "Command.h"

namespace galaxy_v36
{
	namespace game
	{
		class CommonCommand : public Command
		{
		public:
			CommonCommand(const std::string& name);

			virtual void addHandler(CommandHandler* handler) override;
			virtual void removeHandler(CommandHandler* handler) override;
			virtual void removeAllHandlers() override;


		protected:
			virtual CommandHandlers& getHandlers() override;


		private:
			CommandHandlers handlers;
		};
	}
}

#endif // !COMMON_COMMAND_H

