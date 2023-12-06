#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include <entity.h>

class Enemy : public Entity
{
public:
	Enemy();
	virtual ~Enemy();
	void EnemyMover(Point playerPos);
	void Visuals(float deltaTime);
	void killYourself();
	virtual void update(float deltatime);
	int health;
	float speedMultiplier;

private:
	Timer t;
};

#endif
