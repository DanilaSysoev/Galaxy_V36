#ifndef STRING_COMMAND_ARGUMENTS_H
#define STRING_COMMAND_ARGUMENTS_H

#include <string>

#include "CommandArguments.h"

namespace galaxy_v36
{
	namespace game
	{
		class CommonCommandArguments : public CommandArguments
		{
		public:
			CommonCommandArguments(const std::string& argument);

			std::string getArgument() const;


		private:
			std::string argument;
		};
	}
}

#endif // !STRING_COMMAND_ARGUMENTS_H

