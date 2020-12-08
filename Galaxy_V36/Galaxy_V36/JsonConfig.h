#ifndef JSON_CONFIG_H
#define JSON_CONFIG_H

#include <string>
#include <nlohmann/json.hpp>


namespace galaxy_v36
{
	namespace service
	{
		void readJson(const std::string& filename, nlohmann::json& jsonObject);
	}
}

#endif // !JSON_CONFIG_H

