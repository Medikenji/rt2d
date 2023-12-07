#include "altpathenemy.h"

AltPathEnemy::AltPathEnemy(Vector2 *targetEntity) : Enemy()
{
	speed = 250 * speedMultiplier;
	health = 100;
	randomiser = rand() % 4;
	this->targetPosition = targetEntity;
	this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
}

AltPathEnemy::~AltPathEnemy()
{
}
void AltPathEnemy::update(float deltaTime)
{
	goMove(*targetPosition, deltaTime);
	countDown(0.5, deltaTime);
	Enemy::update(deltaTime);
}

void AltPathEnemy::goMove(Point targetPos, float deltaTime)
{
	Vector2 Vectorial = targetPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	goAccelerate(deltaTime, Vectorial, randomiser);
	velocity;
	this->position += velocity;
	velocity *= 0;
}

void AltPathEnemy::goAccelerate(float deltaTime, Vector2 vectorial, int switcher)
{
	switch (switcher)
	{
	case 0:
		velocity.x += -vectorial.y * speed * deltaTime;
		break;
	case 1:
		velocity.y += -vectorial.x * speed * deltaTime;
		break;
	case 2:
		velocity.x += vectorial.y * speed * deltaTime;
		break;
	case 3:
		velocity.y += vectorial.x * speed * deltaTime;
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