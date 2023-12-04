#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include <entity.h>

class Enemy : public Entity
{
public:
	float speedMultiplier = 1;
	void EnemyMover(Point playerPos);
	void Visuals(float deltaTime);
	Enemy();
	virtual ~Enemy();
	virtual void update(float deltatime);

	Player *p;

private:
	Timer t;
	Point velocity;
};

#endif
