// stoicenemy.cpp

#include "stoicenemy.h"

StoicEnemy::StoicEnemy() : Enemy()
{
	// setup enemy
	globalSpeedScaler = speedMultiplier * 0.5;
	this->EnemyScale = (rand() % 10) * 0.1;
	this->scale = Vector2(this->EnemyScale, this->EnemyScale);
	this->sprite()->color = RGBAColor(255, 50, 50, (50 + rand() % 70));
	this->pointAmount = 5;
	this->damageAmount = 2.5;
}

StoicEnemy::~StoicEnemy()
{
}

void StoicEnemy::update(float deltaTime)
{
	// increases enemy size every second
	this->scale += 0.001 * deltaTime * speedMultiplier;
	// functions
	Enemy::update(deltaTime);
	countDown(10, deltaTime);
}

void StoicEnemy::countDown(float countdownTime, float deltaTime)
{
	// starts timer
	if (time > 0)
	{
		time -= 1 * deltaTime;
	}
	else
	{
		// gives enemy random position and size
		float scaleVal = (rand() % 5) * 0.1 / globalSpeedScaler;
		this->scale = Vector2(scaleVal, scaleVal);
		this->position = Vector2(rand() % SWIDTH, rand() % SHEIGHT);
		this->sprite()->color = RGBAColor(255, 50, 50, (50 + rand() % 70));

		// resets timer
		time = countdownTime;
	}
}