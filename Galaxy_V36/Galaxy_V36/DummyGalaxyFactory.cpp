#include <vector>

#include "DummyGalaxyFactory.h"
#include "DrawablesFactory.h"
#include "Galaxy.h"
#include "StarSystem.h"


galaxy_v36::entities::Galaxy* 
galaxy_v36::DummyGalaxyFactory::buildGalaxy(DrawablesFactory* drawablesFactory)
{
    auto galaxy = new entities::Galaxy(std::vector<entities::StarSystem*> {
        new entities::StarSystem("S_1", service::Vector(0, 0), std::vector<entities::SpaceBody*>())
    });

    galaxy->setDrawable(drawablesFactory->getGalaxyDrawable(galaxy));

    return galaxy;
}
