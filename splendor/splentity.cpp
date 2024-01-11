// splentity.cpp

#include "splentity.h"
float Splentity::speedMultiplier = 1.0;
Splentity::Splentity() : Entity()
{
	IsEntityAlive = true;
}

Splentity::~Splentity()
{
}

void Splentity::update(float deltaTime)
{
	speedMultiplier += 0.01 * deltaTime;
}

void Splentity::takeDamage(float deltaTime)
{
	this->health -= 1 * deltaTime;
}

void Splentity::killYourself()
{
	if (this->health <= 0 && this != nullptr)
	{
		this->parent()->removeChild(this);
		this->IsEntityAlive = false;
	}
}

bool Splentity::GetLivingStatus()
{
	return (this->IsEntityAlive);
}