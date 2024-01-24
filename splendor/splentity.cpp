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
	// constantly increases the global speed multiplier
	speedMultiplier += 0.01 * deltaTime;
}

void Splentity::takeDamage(float deltaTime)
{
	// allows all splentities to take damage
	this->health -= 1 * deltaTime;
}

void Splentity::killYourself()
{
	// allows all splentities to die
	if (this->health <= 0 && this != nullptr)
	{
		this->parent()->removeChild(this);
		this->IsEntityAlive = false;
	}
}

bool Splentity::GetLivingStatus()
{
	// allows splenities to return their alive status
	return (this->IsEntityAlive);
}