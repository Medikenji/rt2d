#include "linepathenemy.h"

LinePathEnemy::LinePathEnemy(Vector2 *targetEntity) : Enemy()
{
	speed = 250 * speedMultiplier;
	this->health = 100;
	this->targetPosition = targetEntity;
	this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
}

LinePathEnemy::~LinePathEnemy()
{
}

void LinePathEnemy::update(float deltaTime)
{
	Enemy::update(deltaTime);
	goMove(*targetPosition, deltaTime);
}

void LinePathEnemy::goMove(Point playerPos, float deltaTime)
{
	Vector2 Vectorial = playerPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	this->position += velocity;
	velocity *= 0;
}