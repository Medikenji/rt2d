// stoicenemy.cpp

#include "stoicenemy.h"

StoicEnemy::StoicEnemy()
		: Enemy()
{
	globalSpeedScaler = speedMultiplier * 0.5;
	this->EnemyScale = (rand() % 5) * 0.1;
	this->scale = Vector2(this->EnemyScale, this->EnemyScale);
	this->sprite()->color = RGBAColor(255, 50, 50, 100);
}

StoicEnemy::~StoicEnemy()
{
}

void StoicEnemy::update(float deltaTime)
{
	Enemy::update(deltaTime);
	countDown(10, deltaTime);
}

void StoicEnemy::countDown(float countdownTime, float deltaTime)
{
	if (time > 0)
	{
		time -= 1 * deltaTime;
	}
	else
	{
		globalSpeedScaler = speedMultiplier * 0.5;
		this->EnemyScale = (rand() % 5) * 0.1 * globalSpeedScaler;
		this->scale = Vector2(this->EnemyScale, this->EnemyScale / 2);
		this->position = Vector2(rand() % SWIDTH, rand() % SHEIGHT);
		time = countdownTime;
	}
}