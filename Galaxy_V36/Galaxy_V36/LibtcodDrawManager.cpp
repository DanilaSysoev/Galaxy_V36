#include "LibtcodDrawManager.h"
#include "JsonConfig.h"
#include "libtcod.hpp"

using namespace galaxy_v36::game;
using namespace galaxy_v36::service;
using namespace galaxy_v36::game::libtcod;

void LibtcodDrawManager::prepareDrawing()
{
	for (auto namedConsole : consoles)
		namedConsole.second->clear();
}

void LibtcodDrawManager::flush()
{
	for (auto namedConsole : consoles)
	{
		if (parentNames.find(namedConsole.first) != parentNames.end())
		{
			auto parentName = parentNames[namedConsole.first];
			auto position = positions[namedConsole.first];
			TCODConsole::blit(
				namedConsole.second,
				0,
				0,
				namedConsole.second->getWidth(),
				namedConsole.second->getHeight(),
				consoles[parentName],
				position.getX(),
				position.getY()
			);
		}
	}

	TCODConsole::root->flush();
}

void LibtcodDrawManager::initialize(Game* game)
{
	DrawManager::initialize(game);
}

TCODConsole* LibtcodDrawManager::getConsole(std::string name)
{
	if (consoles.find(name) != consoles.end())
		return consoles[name];
	return nullptr;
}

void LibtcodDrawManager::addConsole(
	const std::string& name,
	TCODConsole* console
)
{
	if (consoles.find(name) != consoles.end())
		delete consoles[name];
	consoles[name] = console;
}

void LibtcodDrawManager::addConsole(
	const std::string& name,
	TCODConsole* console,
	const Vector& position,
	const std::string& parentConsoleName
)
{
	if (consoles.find(name) != consoles.end())
		delete consoles[name];
	consoles[name] = console;
	positions[name] = position;
	parentNames[name] = parentConsoleName;
}

LibtcodDrawManager::~LibtcodDrawManager()
{
	for (auto console: consoles)
		delete console.second;
}