// stoicenemy.cpp

#include "stoicenemy.h"

StoicEnemy::StoicEnemy()
		: Enemy()
{
	globalSpeedScaler = speedMultiplier * 0.5;
	this->EnemyScale = (rand() % 10) * 0.1 * globalSpeedScaler;
	this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
	this->scale = Point2(this->EnemyScale, this->EnemyScale / 2);
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
		this->EnemyScale = (rand() % 10) * 0.1 * globalSpeedScaler;
		this->scale = Point2(this->EnemyScale, this->EnemyScale / 2);
		this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
		time = countdownTime;
	}
}