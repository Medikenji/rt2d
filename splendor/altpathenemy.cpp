#include "altpathenemy.h"

AltPathEnemy::AltPathEnemy(Vector2 *targetEntity) : Enemy()
{ // setup enemy
	this->scale = Vector2(0.03, 0.03);
	this->health = 100;
	this->_Randomiser = rand() % 4;
	this->_pTargetPosition = targetEntity;
	this->sprite()->color = RGBAColor(245, 50, 50, (135 + rand() % 120));
	this->pointAmount = 1;
	this->damageAmount = 2.5;
}

AltPathEnemy::~AltPathEnemy()
{
}

void AltPathEnemy::update(float deltaTime)
{
	Enemy::update(deltaTime);
	// increases enemy size every second
	this->scale += 0.0005 * deltaTime * sGameMultiplier;
	// functions
	countDown(0.5, deltaTime);
	goMove(*this->_pTargetPosition, deltaTime);
}

const void AltPathEnemy::goMove(Vector2 targetPos, float deltaTime)
{
	// makes enemy point and go to player
	Vector2 Vectorial = targetPos - this->position;
	Vectorial.normalize();
	this->_Velocity += Vectorial * this->_Speed * deltaTime;
	goAccelerate(deltaTime, Vectorial, this->_Randomiser);
	this->position += this->_Velocity;

	// resets _Velocity
	this->_Velocity *= 0;
}

const void AltPathEnemy::goAccelerate(float deltaTime, Vector2 vectorial, int switcher)
{
	// updates the speed randomly
	switch (switcher)
	{
	case 0:
		this->_Speed = rand() % 50 * sGameMultiplier;
		break;
	case 1:
		this->_Speed = rand() % 100 * sGameMultiplier;
		break;
	case 2:
		this->_Speed = rand() % 150 * sGameMultiplier;
		break;
	case 3:
		this->_Speed = rand() % 200 * sGameMultiplier;
		break;
	}
}

const void AltPathEnemy::countDown(float countdownTime, float deltaTime)
{
	// starts timer
	if (this->_Time > 0)
	{
		this->_Time -= 1 * deltaTime;
	}
	else
	{
		// changes enemy opacity
		this->sprite()->color = RGBAColor(245, 50, 50, (135 + rand() % 120));

		// randomises speed
		this->_Randomiser = rand() % 4;

		// resets timer
		this->_Time = countdownTime;
	}
}