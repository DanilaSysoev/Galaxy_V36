#include <fstream>

#include "JsonConfig.h"


void galaxy_v36::service::readJson(
	const std::string& filename, 
	nlohmann::json& jsonObject
)
{
    std::ifstream in(filename);
    if (!in)
        return;
    in >> jsonObject;
    in.close();
}
