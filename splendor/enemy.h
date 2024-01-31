#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "splentity.h "

class Enemy : public Splentity
{
public:
	// variables
	int pointAmount;
	Vector2 velocity;
	Vector2 *targetPosition;

	// functions
	Enemy();
	virtual ~Enemy();
	void update(float deltatime);

private:
	// variables
	Timer t;

	// functions
	void Visuals(float deltaTime);
	virtual void Boundry();
};

#endif
