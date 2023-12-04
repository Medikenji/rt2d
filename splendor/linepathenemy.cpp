#include "linepathenemy.h"

LinePathEnemy::LinePathEnemy() : Enemy()
{
	speed = 250 * speedMultiplier;
}

LinePathEnemy::~LinePathEnemy()
{
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