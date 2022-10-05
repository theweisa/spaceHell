#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entity.h"

//BACKGROUND CLASS: plays a background animation; that is all
namespace ent
{
	class Background : public Entity
	{
	private:
		float deltaTime;
		std::string key;
	public:
		//default constructor
		Background() : deltaTime(), key() { };
		//constructor that sets the sprite texture and animation
		inline Background(sf::Texture* newTexture, sf::Vector2f newPos, float scale)
		{
			sprite.setTexture(*newTexture);
			sprite.setOrigin(320, 240);
			sprite.setScale(scale, scale);
			sprite.setPosition(newPos);

			key = "background";
			//640 480
			animations[key] = new Animation(sprite, *newTexture, 5.f, 0, 0, 7, 0, 640, 480);
			deltaTime = 0;
		}
		//updates time (frame)
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