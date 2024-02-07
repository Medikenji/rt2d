// straightenemy.cpp

#include "straightenemy.h"

StraightEnemy::StraightEnemy() : Enemy()
{
	// setup enemy
	this->scale = Vector2(0.1, 0.1);
	this->_Randomiser = rand() % 3;
	this->sprite()->color = RGBAColor(255, 50, 50, 255);
	this->_personalMultiplier = rand() % 10;
	this->_Speed = sGameMultiplier * 800 * _personalMultiplier / 10;
	this->pointAmount = 15;
	this->damageAmount = 0.8;
	spawnSelf();
}

StraightEnemy::~StraightEnemy()
{
}

void StraightEnemy::update(float deltaTime)
{
	// increases enemy size every second
	this->scale += 0.001 * deltaTime * sGameMultiplier;

	// functions
	Enemy::update(deltaTime);
	manageMovement(deltaTime);
	goMove(deltaTime);
	checkBoundry();
}

void StraightEnemy::manageMovement(float deltaTime)
{
	switch (_Randomiser)
	{
	case 0:
		this->_Velocity = Vector2(this->_Speed, 0) * deltaTime;
		break;
	case 1:
		this->_Velocity = Vector2(-_Speed, 0) * deltaTime;
		break;
	case 2:
		this->_Velocity = Vector2(0, this->_Speed) * deltaTime;
		break;
	case 3:
		this->_Velocity = Vector2(0, -this->_Speed) * deltaTime;
		break;
	}
}

void StraightEnemy::goMove(float deltaTime)
{
	this->position += _Velocity;
	this->_Velocity *= 0;
}

void StraightEnemy::spawnSelf()
{
	// spawns enemy in right the right place based on _Randomiser val
	switch (_Randomiser)
	{
	case 0:
		this->position = Vector2(-10, rand() % SHEIGHT);
		break;
	case 1:
		this->position = Vector2(SWIDTH + 10, rand() % SHEIGHT);
		break;
	case 2:
		this->position = Vector2(rand() % SWIDTH, 10);
		break;
	case 3:;
		this->position = Vector2(rand() % SWIDTH, SHEIGHT + 10);
	}
}

void StraightEnemy::checkBoundry()
{
	// keeps enemy within game scene based on _Randomiser val
	switch (_Randomiser)
	{
	case 0:
		if (this->position.x > SWIDTH + 10)
		{
			this->position = Vector2(-10, rand() % SHEIGHT);
		};
		break;
	case 1:
		if (this->position.x < -10)
		{
			this->position = Vector2(SWIDTH + 10, rand() % SHEIGHT);
		};
		break;
	case 2:
		if (this->position.y > SHEIGHT + 10)
		{
			this->position = Vector2(rand() % SWIDTH, 10);
		};
		break;
	case 3:
		if (this->position.y < -10)
		{
			this->position = Vector2(rand() % SWIDTH, SHEIGHT + 10);
		};
		break;
	}
}