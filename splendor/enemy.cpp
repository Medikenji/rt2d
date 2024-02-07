#include "enemy.h"

Enemy::Enemy() : Splentity()
{
	this->addSprite("assets/enemy.tga");
	this->sprite()->color = RED;
	this->position = Vector2(-100, -100);
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	handleVisuals(deltaTime);
	checkBoundry();
}

void Enemy::handleVisuals(float deltaTime)
{
	this->rotation.z += 50 * deltaTime;
	if (this->rotation.z > TWO_PI)
	{
		this->rotation.z -= TWO_PI;
	}
}

void Enemy::checkBoundry()
{
	// checks if enemy is to far out of boundry
	if (this->position.x > SWIDTH + 10 || this->position.y > SHEIGHT + 10 || this->position.x < -10 || this->position.y < -10)
	{
		// randomly places enemy outside of screen
		switch (rand() % 3)
		{
		case 0:
			this->position = Vector2(rand() % SWIDTH, SHEIGHT + 10);
			break;
		case 1:
			this->position = Vector2(rand() % SWIDTH, -10);
			break;
		case 2:
			this->position = Vector2(SWIDTH + 10, rand() % SHEIGHT);
			break;
		case 3:
			this->position = Vector2(-10, rand() % SHEIGHT);
			break;
		}
	}
}