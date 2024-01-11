#include "linepathenemy.h"

LinePathEnemy::LinePathEnemy(Vector2 *targetEntity) : Enemy()
{
	this->health = 100;
	this->targetPosition = targetEntity;
	this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
	this->scale = Point2(0.2, 0.2);
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
	speed = 350 * speedMultiplier;
	Vector2 Vectorial = playerPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	this->position += velocity;
	velocity *= 0;
}