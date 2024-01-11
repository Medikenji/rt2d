// splentity.h

#ifndef SPLENTITY_H
#define SPLENTITY_H

#include <entity.h>

class Splentity : public Entity
{
public:
	Splentity();
	virtual ~Splentity();
	void update(float deltaTime);
	static float speedMultiplier;
	double health;
	void killYourself();
	void takeDamage(float deltaTime);
	bool GetLivingStatus();
	bool IsEntityAlive;

private:
};

#endif /* SPLENTITY_H */
