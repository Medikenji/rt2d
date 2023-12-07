#include "altpathenemy.h"

AltPathEnemy::AltPathEnemy(Vector2 *targetEntity) : Enemy()
{
	speed = 250 * speedMultiplier;
	health = 100;
	this->targetPosition = targetEntity;
}

AltPathEnemy::~AltPathEnemy()
{
}

void AltPathEnemy::update(float deltaTime)
{
	goMove(*targetPosition, deltaTime);
	Enemy::update(deltaTime);
}

void AltPathEnemy::goMove(Point targetPos, float deltaTime)
{
	Vector2 Vectorial = targetPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	goAccelerate(deltaTime, Vectorial, true);
	velocity;
	this->position += velocity;
	velocity *= 0;
}

void AltPathEnemy::goAccelerate(float deltaTime, Vector2 vectorial, bool switcher)
{
	if (switcher)
	{
		velocity.x += -vectorial.y * speed * deltaTime;
	}
	else
	{
		velocity.y += -vectorial.x * speed * deltaTime;
	}
}