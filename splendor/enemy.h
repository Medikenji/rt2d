#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "splentity.h "

class Enemy : public Splentity
{
public:
	Enemy();
	virtual ~Enemy();
	int pointAmount;
	Vector2 velocity;
	Vector2 *targetPosition;
	void update(float deltatime);
	virtual void Boundry();

private:
	Timer t;
	void Visuals(float deltaTime);
	void addForce(float deltaTime);
};

#endif
