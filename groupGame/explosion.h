#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "entity.h"

//will have a sprite that animates, that's literally it
namespace ent
{
	class Explosion : public Entity
	{
	private:
		float deltaTime;
		std::string key;
	public:
		//constructor sets the sprite texture and position, and initializes the animation
		inline Explosion(sf::Texture* newTexture, sf::Vector2f newPos, float scale)
		{
			sprite.setTexture(*newTexture);
			sprite.setOrigin(16.f, 16.f);
			sprite.setScale(2.f * scale, 2.f * scale);
			sprite.setPosition(newPos);

			key = "explosion";
			animations[key] = new Animation(sprite, *newTexture, 10.f, 0, 0, 5, 0, 32, 32);
			deltaTime = 0.f;
		}
		//set the current time (frame)
		inline void setTime(float & time)
		{
			deltaTime = time;
		}
		//update the animation
		inline void update() override
		{
			animations[key]->play(deltaTime);
		}
	};
}
#endif