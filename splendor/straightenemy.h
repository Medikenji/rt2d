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
	int _Randomiser;
	float _Speed;
	float _personalMultiplier;

	// functions
	void update(float deltaTime);
	const void manageMovement(float deltaTime);
	const void goMove(float deltaTime);
	const void spawnSelf();
	void checkBoundry();
};

#endif /* STRAIGHTENEMY_H */
