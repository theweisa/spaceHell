#include "character.h"

//character takes damage
namespace ent
{
	void Character::takeDamage(float damage)
	{
		this->hp -= damage;
	}

	//move the character
	void Character::move(const float dirX, const float dirY)
	{
		this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	}

	//update the animations
	void Character::updateAnimation(std::string key, float & deltaTime)
	{
		this->animations[key]->play(deltaTime);
	}

	//update the fire rate
	void Character::updateFireRate()
	{
		//fire rate updates by 0.5f
		if (this->fireRate < this->maxFireRate)
			this->fireRate += 0.5f;
	}

	//accessors
	const bool Character::canFire()
	{
		//if the fire rate has reached the maximum fire rate, can fire.
		if (this->fireRate >= this->maxFireRate)
		{
			//reset the fire rate and return can fire
			this->fireRate = 0.f;
			return true;
		}
		//if the fire rate is not at the maximum fire rate, cannot fire
		return false;
	}


	const float Character::getDamage() const
	{
		return damage;
	}

	const float Character::getHp() const
	{
		return hp;
	}

	const float Character::getMaxHp() const
	{
		return hpMax;
	}

	const float Character::getFireRate() const
	{
		return maxFireRate;
	}

	const std::string Character::getCurrentAnimation() const
	{
		return currentAnimation;
	}

	const std::string Character::getSpawnKey() const
	{
		return spawnKey;
	}

	const std::string Character::getIdleKey() const
	{
		return idleKey;
	}

	const bool Character::endOfSpawnAnimation()
	{
		return animations[spawnKey]->getEndOfAnimation();
	}

	//mutators
	void Character::setHp(float newHp)
	{
		this->hp = newHp;
	}

	void Character::setDamage(float newDamage)
	{
		this->damage = newDamage;
	}

	void Character::setMovementSpeed(float newMS)
	{
		this->movementSpeed = newMS;
	}

	//mutator
	void Character::setFireRate(float newFireRate)
	{
		this->maxFireRate = newFireRate;
		this->fireRate = 0;
	}

	void Character::setSpawnAnimation(std::string key, sf::Texture * textureSheet, int endFrameX, int endFrameY, int width, int height)
	{
		this->spawnKey = key;
		//animation name, speed, startFrameX, startFrameY, endFrameX, endFrameY, width, height
		this->animations[key] = new Animation(sprite, *textureSheet, 10.f, 0, 0, endFrameX, endFrameY, width, height); //4, 0, 32, 32
		this->currentAnimation = "spawn";
	}

	void Character::setIdleAnimation(std::string key, sf::Texture * textureSheet, int endFrameX, int endFrameY, int width, int height)
	{
		this->idleKey = key;
		this->animations[key] = new Animation(sprite, *textureSheet, 10.f, 0, 0, endFrameX, endFrameY, width, height); //11, 0, 32, 32
		this->currentAnimation = "idle";
	}

	void Character::setCurrentAnimation(std::string newAnimation)
	{
		this->currentAnimation = newAnimation;
	}
}