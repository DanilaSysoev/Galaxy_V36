#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

namespace galaxy_v36
{
	namespace game
	{
		class CommandProcessor
		{
		public:
			virtual void processCommands() = 0;

			virtual ~CommandProcessor();
		};
	}
}
#endif  // !COMMAND_PROCESSOR_H

