#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "splentity.h "

class Enemy : public Splentity
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
	Vector2 velocity;
	Vector2 *targetPosition;
	virtual void Boundry();

private:
	Timer t;
};

#endif
