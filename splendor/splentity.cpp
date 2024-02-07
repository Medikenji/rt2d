// splentity.cpp

#include "splentity.h"
float Splentity::sGameMultiplier = 1.0;
Splentity::Splentity() : Entity()
{
	IsEntityAlive = true;
}

Splentity::~Splentity()
{
}

void Splentity::update(float deltaTime)
{
	// constantly increases the global _Speed multiplier
	sGameMultiplier += 0.005 * sGameMultiplier * deltaTime;
}

void Splentity::takeDamage(float deltaTime, float damageAmount)
{
	// allows all splentities to take damage
	this->health -= damageAmount * deltaTime;
}

void Splentity::killYourself()
{
	// allows all splentities to die
	if (this->health <= 0 && this != nullptr)
	{
		this->IsEntityAlive = false;
		this->parent()->removeChild(this);
	}
}

bool Splentity::getLivingStatus()
{
	// allows splenities to return their alive status
	return (this->IsEntityAlive);
}