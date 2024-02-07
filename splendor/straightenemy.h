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
	void manageMovement(float deltaTime);
	void goMove(float deltaTime);
	void spawnSelf();
	void checkBoundry();
};

#endif /* STRAIGHTENEMY_H */
