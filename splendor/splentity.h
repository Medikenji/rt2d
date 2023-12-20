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
	float speedMultiplier;

private:
};

#endif /* SPLENTITY_H */
