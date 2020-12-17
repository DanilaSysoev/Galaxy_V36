#ifndef COMMAND_HANDLER_PROVIDER_H
#define COMMAND_HANDLER_PROVIDER_H

#include <string>

namespace galaxy_v36
{
	namespace game
	{
		class CommandHandler;

		class CommandHandlerProvider
		{
		public:
			virtual CommandHandler* getHandler(const std::string& tag) = 0;

			virtual ~CommandHandlerProvider();
		};
	}
}

#endif // !COMMAND_HANDLER_PROVIDER_H