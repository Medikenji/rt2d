// straightenemy.h

#ifndef STRAIGHTENEMY_H
#define STRAIGHTENEMY_H

#include "enemy.h"

class StraightEnemy : public Enemy
{
public:
	StraightEnemy();
	virtual ~StraightEnemy();

private:
	// variables
	int randomiser;
	float speed;
	float personalMultiplier;

	// functions
	void update(float deltaTime);
	void ManageMovement(float deltaTime);
	void GoMove(float deltaTime);
	void Spawn();
	void Boundry();
};

#endif /* STRAIGHTENEMY_H */
