#include "LibtcodGameplay.h"
#include "CommandHandler.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::game::libtcod;


LibtcodGameplay::LibtcodGameplay(const std::string& name)
	: name(name)
	, game(nullptr)
	, active(false)
	, handlers()
	, drawables()
{
}

std::string LibtcodGameplay::getName() const
{
	return name;
}

LibtcodGame* LibtcodGameplay::getGame() const
{
	return game;
}

void LibtcodGameplay::setGame(LibtcodGame* game)
{
	this->game = game;
}

void LibtcodGameplay::activate()
{
	active = true;
	for (auto handler : handlers)
		handler->enable();
}

void LibtcodGameplay::deactivate()
{
	active = false;
	for (auto handler : handlers)
		handler->disable();
}

bool LibtcodGameplay::isActive()
{
	return active;
}

void LibtcodGameplay::addHandler(CommandHandler* handler)
{
	handlers.insert(handler);
}

void LibtcodGameplay::deleteHandler(CommandHandler* handler)
{
	handlers.erase(handler);
}

const std::set<Drawable*>& LibtcodGameplay::getDrawables() const
{
	return drawables;
}

void LibtcodGameplay::addDrawable(Drawable* drawable)
{
	drawables.insert(drawable);
}

void LibtcodGameplay::deleteDrawable(Drawable* drawable)
{
	drawables.erase(drawable);
}
