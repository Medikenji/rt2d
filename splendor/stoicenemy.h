// stoicenemy.h

#ifndef STOICENEMY_H
#define STOICENEMY_H

#include "enemy.h"

class StoicEnemy : public Enemy
{
public:
	StoicEnemy();
	virtual ~StoicEnemy();

private:
	// variables
	float time;
	float EnemyScale;
	float globalSpeedScaler;

	// functions
	void countDown(float countdownTime, float deltaTime);
	void update(float deltaTime);
};

#endif /* STOICENEMY_H */
