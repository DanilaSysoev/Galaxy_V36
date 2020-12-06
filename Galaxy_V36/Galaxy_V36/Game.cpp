#include "Game.h"
#include "DrawManager.h"
#include "UpdateManager.h"
#include "CommandProcessor.h"
#include "Updatable.h"
#include "Drawable.h"

using namespace galaxy_v36::game;
using namespace galaxy_v36::entities;


Game::Game()
	: drawManager(nullptr)
	, commandProcessor(nullptr)
	, updateManager(nullptr)
{}

void Game::initialize(
	game::DrawManager* drawManager,
	game::CommandProcessor* commandProcesor,
	game::UpdateManager* updateManager
)
{
	this->drawManager = drawManager;
	this->commandProcessor = commandProcesor;
	this->updateManager = updateManager;

	drawManager->setGame(this);
	commandProcesor->setGame(this);
	updateManager->setGame(this);

	game = this;
}

DrawManager* Game::getDrawManager()
{
	return drawManager;
}

CommandProcessor* Game::getCommandProcessor()
{
	return commandProcessor;
}

UpdateManager* Game::getUpdateManager()
{
	return updateManager;
}

void Game::run()
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

void Game::drawAll()
{
	drawManager->prepareDrawing();
	for (auto drawable : getDravables()) {
		drawManager->draw(drawable);
	}
	drawManager->flush();
}

void Game::updateAll()
{
	updateManager->prepareUpdate();
	for (auto updatable : getUpdatables()) {
		updateManager->update(updatable);
	}
	updateManager->endUpdate();
}

Game::~Game() 
{
	delete drawManager;
	delete updateManager;
	delete commandProcessor;
}

Game* Game::getGame()
{
	return Game::game;
}

bool DrawableComparator::operator()(Drawable* left, Drawable* right) const
{
	return left->getDrawPriority() > right->getDrawPriority();
}

bool UpdatableComparator::operator()(
	Updatable*& left,
	Updatable*& right
) const
{
	return left->getUpdatePriority() > right->getUpdatePriority();
}

Game* Game::game = nullptr;