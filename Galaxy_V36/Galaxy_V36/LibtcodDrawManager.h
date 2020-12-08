#ifndef LIBTCOD_DRAW_MANAGER_H
#define LIBTCOD_DRAW_MANAGER_H

#include <map>

#include <nlohmann/json.hpp>

#include "libtcod.hpp"

#include "DrawManager.h"
#include "Vector.h"

using namespace galaxy_v36::service;

namespace galaxy_v36
{
	namespace game
	{
		namespace libtcod
		{
			class LibtcodDrawManager : public DrawManager
			{
			public:
				virtual void prepareDrawing() override;
				virtual void flush() override;
				virtual void initialize(Game* game) override;

				TCODConsole* getConsole(std::string name);

				void addConsole(
					const std::string& name,
					TCODConsole* console
				);
				void addConsole(
					const std::string& name, 
					TCODConsole* console, 
					const Vector& position, 
					const std::string& parentConsoleName
				);
				
				virtual ~LibtcodDrawManager();


			private:
				std::map<std::string, TCODConsole*> consoles;
				std::map<std::string, Vector> positions;
				std::map<std::string, std::string> parentNames;
			};
		}
	}
}

#endif  // !LIBTCOD_DRAW_MANAGER_H
