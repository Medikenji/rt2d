// splentity.h

#ifndef SPLENTITY_H
#define SPLENTITY_H

#include <entity.h>

class Splentity : public Entity
{
public:
	Splentity();
	virtual ~Splentity();
	float speedMultiplier;

private:
	/* add your private declarations */
};

#endif /* SPLENTITY_H */
