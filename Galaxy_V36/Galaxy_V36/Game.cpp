#include "Game.h"
#include "DrawManager.h"
#include "UpdateManager.h"
#include "CommandProcessor.h"
#include "Updatable.h"
#include "Drawable.h"

galaxy_v36::game::Game::Game()
	: drawManager(nullptr)
	, commandProcessor(nullptr)
	, updateManager(nullptr)
{}

void 
galaxy_v36::game::Game::initialize( game::DrawManager* drawManager
	                                , game::CommandProcessor* commandProcesor
	                                , game::UpdateManager* updateManager)
{
	this->drawManager = drawManager;
	this->commandProcessor = commandProcesor;
	this->updateManager = updateManager;

	drawManager->setGame(this);
	commandProcesor->setGame(this);
	updateManager->setGame(this);

	game = this;
}

galaxy_v36::game::DrawManager*
galaxy_v36::game::Game::getDrawManager()
{
	return drawManager;
}
galaxy_v36::game::CommandProcessor*
galaxy_v36::game::Game::getCommandProcessor()
{
	return commandProcessor;
}
galaxy_v36::game::UpdateManager*
galaxy_v36::game::Game::getUpdateManager()
{
	return updateManager;
}

void 
galaxy_v36::game::Game::run()
{
	prepareGame();
	while (!isGameEnd())
	{
		drawAll();
		commandProcessor->processCommands();
		updateAll();
	}
	finishGame();
}

void 
galaxy_v36::game::Game::drawAll()
{
	drawManager->prepareDrawing();
	for (auto drawable : getDravables()) {
		drawManager->draw(drawable);
	}
	drawManager->flush();
}

void 
galaxy_v36::game::Game::updateAll()
{
	updateManager->prepareUpdate();
	for (auto updatable : getUpdatables()) {
		updateManager->update(updatable);
	}
	updateManager->endUpdate();
}

galaxy_v36::game::Game::~Game() 
{
	delete drawManager;
	delete updateManager;
	delete commandProcessor;
}

galaxy_v36::game::Game*
galaxy_v36::game::Game::getGame()
{
	return Game::game;
}

bool
galaxy_v36::game::DrawableComparator::operator()(Drawable* left, Drawable* right) const
{
	return left->getDrawPriority() > right->getDrawPriority();
}

bool
galaxy_v36::game::UpdatableComparator::operator()(Updatable*& left, Updatable*& right) const
{
	return left->getUpdatePriority() > right->getUpdatePriority();
}

galaxy_v36::game::Game* galaxy_v36::game::Game::game = nullptr;