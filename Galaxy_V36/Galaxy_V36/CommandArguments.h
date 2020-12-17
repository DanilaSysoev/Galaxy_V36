#ifndef COMMAND_ARGUMENTS_H
#define COMMAND_ARGUMENTS_H

namespace galaxy_v36
{
	namespace game
	{
		class CommandArguments
		{
		public:
			static const CommandArguments& getEmpty();

			virtual ~CommandArguments();

		private:
			static const CommandArguments& empty;
		};
	}
}

#endif // !COMMAND_ARGUMENTS_H

