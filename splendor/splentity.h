// splentity.h

#ifndef SPLENTITY_H
#define SPLENTITY_H

#include <entity.h>

class Splentity : public Entity
{
public:
	// variables
	double health;
	static float speedMultiplier;
	float damageAmount;

	// functions
	Splentity();
	virtual ~Splentity();
	void takeDamage(float deltaTime, float damageAmount);
	bool GetLivingStatus();
	bool IsEntityAlive;

protected:
	// functions
	void update(float deltaTime);
	void killYourself();
};

#endif /* SPLENTITY_H */
