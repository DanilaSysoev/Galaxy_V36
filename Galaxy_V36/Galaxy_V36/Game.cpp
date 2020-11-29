#include "Game.h"
#include "DrawManager.h"
#include "UpdateManager.h"
#include "CommandProcessor.h"

galaxy_v36::game::Game::Game()
	: drawManager(nullptr)
	, commandProcesor(nullptr)
	, updateManager(nullptr)
{}

void galaxy_v36::game::Game::initialize( game::DrawManager* drawManager
	                                   , game::CommandProcessor* commandProcesor
	                                   , game::UpdateManager* updateManager)
{
	this->drawManager = drawManager;
	this->commandProcesor = commandProcesor;
	this->updateManager = updateManager;
}

void galaxy_v36::game::Game::run()
{
	prepareGame();
	while (!isGameEnd())
	{
		drawAll();
		commandProcesor->processCommands();
		updateAll();
	}
	finishGame();
}

void galaxy_v36::game::Game::drawAll()
{
	drawManager->prepareDrawing();
	for (auto drawable : getDravables()) {
		drawManager->draw(drawable);
	}
	drawManager->flush();
}

void galaxy_v36::game::Game::updateAll()
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
	delete commandProcesor;
}