#ifndef UPGRADES_H
#define UPGRADES_H

#include "entity.h"

using namespace sf;

/*
Upgrade class:
-drops where the enemy died
-despawns after x time
-has an idle animation
*/
namespace ent
{
	class Upgrade : public Entity 
	{
	private:
		std::string key;		//key for the upgrade idle animation
		float deltaTime;		//delta time
		int type;				//type of upgrade
		float despawnTimer;		//despawn timer
		float despawnTimerMax;

	public:
		//constructor
		Upgrade(Texture* texture, Vector2f position, float despawnTimerMax, int type, float & currentTime, float scale);

		//mutator
		void setTime(float & time);

		//accessor
		const float getTime() const;
		const int getType() const;

		//functions
		//check if the upgrade despawn timer exceeds the max timer
		bool isDespawned();
		void update() override;
	};
}
#endif