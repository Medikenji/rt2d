#include "altpathenemy.h"

AltPathEnemy::AltPathEnemy(Vector2 *targetEntity) : Enemy()
{
	this->scale = Vector2(0.3, 0.3);
	health = 100;
	randomiser = rand() % 2;
	this->targetPosition = targetEntity;
	this->position = Vector2(rand() % SWIDTH, rand() % SHEIGHT);
}

AltPathEnemy::~AltPathEnemy()
{
}
void AltPathEnemy::update(float deltaTime)
{
	Enemy::update(deltaTime);
	countDown(0.5, deltaTime);
	goMove(*targetPosition, deltaTime);
}

void AltPathEnemy::goMove(Vector2 targetPos, float deltaTime)
{
	Vector2 Vectorial = targetPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	goAccelerate(deltaTime, Vectorial, randomiser);
	this->position += velocity;
	velocity *= 0;
}

void AltPathEnemy::goAccelerate(float deltaTime, Vector2 vectorial, int switcher)
{
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
	if (time > 0)
	{
		time -= 1 * deltaTime;
	}
	else
	{
		randomiser = rand() % 4;
		time = countdownTime;
	}
}