#ifndef LIBTCOD_COMMAND_PROCESSOR_H
#define LIBTCOD_COMMAND_PROCESSOR_H

#include "CommandProcessor.h"

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodCommandProcessor : public CommandProcessor
			{
			public:
				virtual void processCommands() override;
			};
		}
	}
}

#endif  // !LIBTCOD_COMMAND_PROCESSOR_H
