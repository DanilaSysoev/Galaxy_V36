#ifndef STAR_SYSTEM_DRAWABLE_H
#define STAR_SYSTEM_DRAWABLE_H

#include "Drawable.h"

namespace galaxy_v36
{
	namespace entities
	{
		class StarSystem;
	}

	namespace game
	{
		class StarSystemDrawable : public Drawable
		{
		public:
			StarSystemDrawable(
				Camera* camera, 
				entities::StarSystem* starSystem
			);

			entities::StarSystem* getStarSystem();
			Camera* getCamera() const override;

			~StarSystemDrawable();


		private:
			entities::StarSystem* starSystem;
			Camera* camera;
		};
	}
}

#endif // !STAR_SYSTEM_DRAWABLE_H

