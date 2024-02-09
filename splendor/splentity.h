// splentity.h

#ifndef SPLENTITY_H
#define SPLENTITY_H

#include <entity.h>

class Splentity : public Entity
{
public:
	// variables
	double health;
	static float sGameMultiplier;
	float damageAmount;
	bool IsEntityAlive;

	// functions
	Splentity();
	virtual ~Splentity();
	const void takeDamage(float deltaTime, float damageAmount);
	const bool getLivingStatus() const;

protected:
	// functions
	void update(float deltaTime);
	const void killYourself();
};

#endif /* SPLENTITY_H */
