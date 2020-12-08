#include "LibtcodDrawablesComponent.h"

using namespace galaxy_v36::game::libtcod;

std::string galaxy_v36::game::libtcod::LibtcodDrawablesComponent::getConsoleName() const
{
	return consoleName;
}

void LibtcodDrawablesComponent::setConsoleName(const std::string& consoleName)
{
	this->consoleName = consoleName;
}
