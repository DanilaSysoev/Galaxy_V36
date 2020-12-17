#include "CommonCommandArguments.h"

using namespace galaxy_v36::game;

CommonCommandArguments::CommonCommandArguments(const std::string& argument)
	: argument(argument)
{
}

std::string CommonCommandArguments::getArgument() const
{
	return argument;
}
