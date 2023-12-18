#include "altpathenemy.h"

AltPathEnemy::AltPathEnemy(Vector2 *targetEntity) : Enemy()
{
	health = 100;
	randomiser = rand() % 2;
	this->targetPosition = targetEntity;
	this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
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

void AltPathEnemy::goMove(Point targetPos, float deltaTime)
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
		speed = 50 * speedMultiplier;
		break;
	case 1:
		speed = 100 * speedMultiplier;
		break;
	case 2:
		speed = 150 * speedMultiplier;
		break;
	case 3:
		speed = 200 * speedMultiplier;
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