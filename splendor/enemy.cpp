#include "enemy.h"

Enemy::Enemy() : Splentity()
{
	this->addSprite("assets/enemy.tga");
	this->sprite()->color = RED;
	this->scale = Point2(0.2, 0.2);
}

Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	Visuals(deltaTime);
	addForce(deltaTime);
}

void Enemy::Visuals(float deltaTime)
{
	this->rotation.z += 50 * deltaTime;
	if (this->rotation.z > TWO_PI)
	{
		this->rotation.z -= TWO_PI;
	}
	RGBAColor color = this->sprite()->color;
	this->sprite()->color = Color::rotate(color, 0.01f);
}

void Enemy::killYourself()
{
	parent()->removeChild(this);
}

void Enemy::addForce(float deltaTime)
{
	// gravity
	velocity += Vector2(0, 350) * speedMultiplier * deltaTime;
}