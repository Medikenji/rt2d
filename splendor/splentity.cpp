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
	std::cout << speedMultiplier << std::endl;
	// constantly increases the global speed multiplier
	speedMultiplier += 0.005 * speedMultiplier * deltaTime;
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
		this->IsEntityAlive = false;
		this->parent()->removeChild(this);
	}
}

bool Splentity::GetLivingStatus()
{
	// allows splenities to return their alive status
	return (this->IsEntityAlive);
}