#include "linepathenemy.h"

LinePathEnemy::LinePathEnemy(Vector2 *targetEntity) : Enemy()
{
	// setup enemy
	this->health = 100;
	this->targetPosition = targetEntity;
	this->scale = Vector2(0.1, 0.1);
	this->sprite()->color = RGBAColor(255, 0, 0, 255);
}

LinePathEnemy::~LinePathEnemy()
{
}

void LinePathEnemy::update(float deltaTime)
{
	// functions
	Enemy::update(deltaTime);
	goMove(*targetPosition, deltaTime);
}

void LinePathEnemy::goMove(Point playerPos, float deltaTime)
{
	// updates the speed
	speed = 350 * speedMultiplier;

	// makes enemy point and go to player
	Vector2 Vectorial = playerPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	this->position += velocity;

	// resets enemy velocity
	velocity *= 0;
}