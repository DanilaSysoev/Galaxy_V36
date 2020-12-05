#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <set>

namespace galaxy_v36
{
	namespace game
	{
		class CommandHandler;
		class CommandArguments;

		class CommandHandlerComparator
		{
		public:
			bool operator()(const CommandHandler* lo, const CommandHandler* ro) const;
		};

		using CommandHandlers = std::multiset<CommandHandler*, CommandHandlerComparator>;

		class Command
		{
		public:
			Command(std::string name);

			std::string getName() const;

			virtual void addHandler(CommandHandler* handler) = 0;
			virtual void removeHandler(CommandHandler* handler) = 0;
			virtual void removeAllHandlers() = 0;			
			virtual const CommandArguments& getArguments() = 0;

			void execute();

			virtual ~Command();


		protected:
			virtual CommandHandlers& getHandlers() = 0;


		private:
			std::string name;
		};
	}
}


#endif // !COMMAND_H

