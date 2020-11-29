#include "GameFactory.h"
#include "LibtcodGameFactory.h"

std::shared_ptr<galaxy_v36::GameFactory>
galaxy_v36::GameFactory::getFactory(const galaxy_v36::GameType& gameType)
{
	switch (gameType)
	{
	case GameType::LIBTCOD:
		return std::make_shared<LibtcodGameFactory>();
	}

	return nullptr;
}