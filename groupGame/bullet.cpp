#include "bullet.h"

namespace ent
{
	//bullet constructor
	Bullet::Bullet(sf::Texture& texture, int bulletType, sf::FloatRect newHitbox, sf::Vector2f pos, float angle, sf::Vector2f dir, float newMovementSpeed, float scale)
	{
		this->sprite.setTexture(texture);

		//0 is playerBullet, 10 is basicEnemyBullet, 11 is thinEnemyBullet, 12 is bigEnemyBullet, 13 is bouncingEnemyBullet
		this->type = bulletType;

		//set sprite origin and position
		this->sprite.setOrigin(sprite.getTexture()->getSize().x * 0.5f, sprite.getTexture()->getSize().y * 0.5f);
		this->sprite.setPosition(pos);
		this->sprite.scale(2.f * scale, 2.f * scale);

		//set direction it moves and the speed
		this->direction = dir;
		this->movementSpeed = newMovementSpeed;

		//set the hitbox
		this->setHitbox(newHitbox);

		//set the angle it rotates
		this->rotateAngle = angle;

		//set if the bullet bounces based on the type passed in
		if (type == 13)
			this->maxBounce = 3;
		else
			this->maxBounce = 0;

		//update the rotation
		this->updateRotation();
	}

	//accessors
	const int Bullet::getType() const
	{
		return type;
	}

	const sf::Vector2f Bullet::getBasePos() const
	{
		return basePos;
	}

	const int Bullet::getMaxBounce() const
	{
		return maxBounce;
	}

	const sf::Vector2f Bullet::getDir() const
	{
		return direction;
	}

	//mutators
	void Bullet::setMaxBounce(int newMaxBounce)
	{
		this->maxBounce = newMaxBounce;
	}

	void Bullet::setDir(sf::Vector2f newDir)
	{
		this->direction = newDir;
	}

	void Bullet::setBasePos(sf::Vector2f newPos)
	{
		this->basePos = newPos;
	}

	//update the bullets movement
	void Bullet::update()
	{
		//bullet moves at the set direction; if bullet type is 12 (cluster), has a different movement calculation to have a burst of movement speed
		if (type == 12)
		{
			this->sprite.move(0.0125f * movementSpeed * (basePos.x - sprite.getPosition().x), 0.0125f * movementSpeed * (basePos.y - sprite.getPosition().y));
		}
		else
			this->sprite.move(this->movementSpeed * this->direction);
	}
}