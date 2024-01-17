#include "enemy.h"

Enemy::Enemy() : Splentity()
{
	this->addSprite("assets/enemy.tga");
	this->sprite()->color = RED;
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	Visuals(deltaTime);
}

void Enemy::Visuals(float deltaTime)
{
	this->rotation.z += 50 * deltaTime;
	if (this->rotation.z > TWO_PI)
	{
		this->rotation.z -= TWO_PI;
	}
}

void Enemy::killYourself()
{
	parent()->removeChild(this);
}

void Enemy::addForce(float deltaTime)
{
	// gravity
	velocity += Vector2(0, 350) * (speedMultiplier * 0.9) * deltaTime;
}