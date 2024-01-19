// straightenemy.cpp

#include "straightenemy.h"

StraightEnemy::StraightEnemy() : Enemy()
{
	this->scale = Vector2(0.1, 0.1);
	this->randomiser = rand() % 3;
	this->sprite()->color = RGBAColor(255, 50, 50, 255);
	this->personalMultiplier = rand() % 10;
	this->speed = speedMultiplier * 800 * personalMultiplier / 10;
	Respawn();
}

StraightEnemy::~StraightEnemy()
{
}

void StraightEnemy::update(float deltaTime)
{
	Enemy::update(deltaTime);
	ManageMovement(deltaTime);
	GoMove(deltaTime);
	Boundry();
}

void StraightEnemy::ManageMovement(float deltaTime)
{
	switch (randomiser)
	{
	case 0:
		this->velocity = Vector2(this->speed, 0) * deltaTime;
		break;
	case 1:
		this->velocity = Vector2(-speed, 0) * deltaTime;
		break;
	case 2:
		this->velocity = Vector2(0, this->speed) * deltaTime;
		break;
	case 3:
		this->velocity = Vector2(0, -this->speed) * deltaTime;
		break;
	}
}

void StraightEnemy::GoMove(float deltaTime)
{
	this->position += velocity;
	this->velocity *= 0;
}

void StraightEnemy::Respawn()
{
	switch (randomiser)
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

void StraightEnemy::Boundry()
{
	switch (randomiser)
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