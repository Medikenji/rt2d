#include "linepathenemy.h"

LinePathEnemy::LinePathEnemy(Vector2 *targetEntity) : Enemy()
{
	speed = 250 * speedMultiplier;
	this->health = 100;
	this->targetPosition = targetEntity;
}

LinePathEnemy::~LinePathEnemy()
{
}

void LinePathEnemy::update(float deltaTime)
{
	goMove(*targetPosition, deltaTime);
	Enemy::update(deltaTime);
}

void LinePathEnemy::goMove(Point playerPos, float deltaTime)
{
	Vector2 Vectorial = playerPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	velocity;
	this->position += velocity;
	velocity *= 0;
}