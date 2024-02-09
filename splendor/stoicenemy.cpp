// stoicenemy.cpp

#include "stoicenemy.h"

StoicEnemy::StoicEnemy() : Enemy()
{
	// setup enemy
	_globalSpeedScaler = sGameMultiplier * 0.5;
	this->_enemyScale = (rand() % 10) * 0.1;
	this->scale = Vector2(this->_enemyScale, this->_enemyScale);
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
	this->scale += 0.001 * deltaTime * sGameMultiplier;
	// functions
	Enemy::update(deltaTime);
	countDown(10, deltaTime);
}

const void StoicEnemy::countDown(float countdownTime, float deltaTime)
{
	// starts _pTimer
	if (_Time > 0)
	{
		_Time -= 1 * deltaTime;
	}
	else
	{
		// gives enemy random position and size
		float scaleVal = (rand() % 5) * 0.1 / _globalSpeedScaler;
		this->scale = Vector2(scaleVal, scaleVal);
		this->position = Vector2(rand() % SWIDTH, rand() % SHEIGHT);
		this->sprite()->color = RGBAColor(255, 50, 50, (50 + rand() % 70));

		// resets _pTimer
		_Time = countdownTime;
	}
}