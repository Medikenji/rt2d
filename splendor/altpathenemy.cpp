#include "altpathenemy.h"

AltPathEnemy::AltPathEnemy() : Enemy()
{
	speed = 250 * speedMultiplier;
}

AltPathEnemy::~AltPathEnemy()
{
}

void AltPathEnemy::goMove(Point playerPos, float deltaTime)
{
	Vector2 Vectorial = playerPos - this->position;
	Vectorial.normalize();
	velocity += Vectorial * speed * deltaTime;
	goAccelerate();
	velocity;
	this->position += velocity;
	velocity *= 0;
}
void AltPathEnemy::goAccelerate()
{
	velocity.x *= abs(velocity.x) * 15;
	velocity.y *= abs(velocity.y) * 15;
}