#include "altpathenemy.h"

AltPathEnemy::AltPathEnemy(Vector2 *targetEntity) : Enemy()
{ // setup enemy
	this->scale = Vector2(0.025, 0.025);
	health = 100;
	randomiser = rand() % 4;
	this->targetPosition = targetEntity;
	this->sprite()->color = RGBAColor(245, 50, 50, (135 + rand() % 120));
}

AltPathEnemy::~AltPathEnemy()
{
}

void AltPathEnemy::update(float deltaTime)
{
	Enemy::update(deltaTime);
	// increases enemy size every second
	this->scale += 0.001 * deltaTime * speedMultiplier;
	// functions
	countDown(0.5, deltaTime);
	goMove(*targetPosition, deltaTime);
}

void AltPathEnemy::goMove(Vector2 targetPos, float deltaTime)
{
	// makes enemy point and go to player
	Vector2 Vectorial = targetPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	goAccelerate(deltaTime, Vectorial, randomiser);
	this->position += velocity;

	// resets velocity
	velocity *= 0;
}

void AltPathEnemy::goAccelerate(float deltaTime, Vector2 vectorial, int switcher)
{
	// updates the speed randomly
	switch (switcher)
	{
	case 0:
		speed = rand() % 100 * speedMultiplier;
		break;
	case 1:
		speed = rand() % 200 * speedMultiplier;
		break;
	case 2:
		speed = rand() % 300 * speedMultiplier;
		break;
	case 3:
		speed = rand() % 400 * speedMultiplier;
		break;
	}
}

void AltPathEnemy::countDown(float countdownTime, float deltaTime)
{
	// starts timer
	if (time > 0)
	{
		time -= 1 * deltaTime;
	}
	else
	{
		// changes enemy opacity
		this->sprite()->color = RGBAColor(245, 50, 50, (135 + rand() % 120));

		// randomises speed
		randomiser = rand() % 4;

		// resets timer
		time = countdownTime;
	}
}