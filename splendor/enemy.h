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
	void addForce(float deltaTime);
	void update(float deltatime);
	int health;
	float speedMultiplier;
	Vector2 velocity;

private:
	Timer t;
};

#endif
