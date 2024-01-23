// stoicenemy.cpp

#include "stoicenemy.h"

StoicEnemy::StoicEnemy() : Enemy()
{
	globalSpeedScaler = speedMultiplier * 0.5;
	this->EnemyScale = (rand() % 10) * 0.1;
	this->scale = Vector2(this->EnemyScale, this->EnemyScale);
	this->sprite()->color = RGBAColor(255, 50, 50, (50 + rand() % 70));
}

StoicEnemy::~StoicEnemy()
{
}

void StoicEnemy::update(float deltaTime)
{
	this->scale += 0.001 * deltaTime * speedMultiplier;
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
		float scaleVal = (rand() % 5) * 0.1 / globalSpeedScaler;
		this->scale = Vector2(scaleVal, scaleVal);
		this->position = Vector2(rand() % SWIDTH, rand() % SHEIGHT);
		this->sprite()->color = RGBAColor(255, 50, 50, (50 + rand() % 70));
		time = countdownTime;
	}
}