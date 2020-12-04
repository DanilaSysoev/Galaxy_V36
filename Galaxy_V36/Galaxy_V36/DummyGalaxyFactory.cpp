#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

#include "DummyGalaxyFactory.h"
#include "DrawablesFactory.h"
#include "Galaxy.h"
#include "StarSystem.h"
#include "Vector.h"


galaxy_v36::entities::Galaxy* 
galaxy_v36::DummyGalaxyFactory::buildGalaxy(DrawablesFactory* drawablesFactory)
{
    const int STAR_SYSTEMS_COUNT = 10;
    const int MIN_STAR_SYSTEM_X_POS = 5;
    const int MAX_STAR_SYSTEM_X_POS = 100;
    const int MIN_STAR_SYSTEM_Y_POS = 5;
    const int MAX_STAR_SYSTEM_Y_POS = 60;

    srand(time(nullptr));

    std::vector<entities::StarSystem*> starSystems;

    for (int i = 0; i < STAR_SYSTEMS_COUNT; ++i)
    {
        int x = rand() % (MAX_STAR_SYSTEM_X_POS - MIN_STAR_SYSTEM_X_POS) + MIN_STAR_SYSTEM_X_POS;
        int y = rand() % (MAX_STAR_SYSTEM_Y_POS - MIN_STAR_SYSTEM_Y_POS) + MIN_STAR_SYSTEM_Y_POS;

        starSystems.push_back(new entities::StarSystem("S_" + std::to_string(i), service::Vector(x, y), std::vector<entities::SpaceBody*>()));
    }

    auto galaxy = new entities::Galaxy(starSystems);

    galaxy->setDrawable(drawablesFactory->getGalaxyDrawable(galaxy));

    return galaxy;
}
