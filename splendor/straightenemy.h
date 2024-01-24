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
	void update(float deltaTime);
	void ManageMovement(float deltaTime);
	void GoMove(float deltaTime);
	int randomiser;
	float speed;
	float personalMultiplier;
	void Spawn();
	void Boundry();
};

#endif /* STRAIGHTENEMY_H */
