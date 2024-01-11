// stoicenemy.h

#ifndef STOICENEMY_H
#define STOICENEMY_H

#include "enemy.h"

class StoicEnemy : public Enemy
{
public:
	StoicEnemy();
	virtual ~StoicEnemy();
	void update(float deltaTime);

private:
	void countDown(float countdownTime, float deltaTime);
	float time;
	float EnemyScale;
	float globalSpeedScaler;
};

#endif /* STOICENEMY_H */
