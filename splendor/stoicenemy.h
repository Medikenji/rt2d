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
	float _Time;
	float _enemyScale;
	float _globalSpeedScaler;

	// functions
	void update(float deltaTime);
	const void countDown(float countdownTime, float deltaTime);
};

#endif /* STOICENEMY_H */
