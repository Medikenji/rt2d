#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "splentity.h "

class Enemy : public Splentity
{
public:
	// variables
	int pointAmount;
	Vector2 _Velocity;
	Vector2 *pTargetPosition;

	// functions
	Enemy();
	virtual ~Enemy();
	void update(float deltatime);

private:
	// variables
	Timer _T;

	// functions
	const void handleVisuals(float deltaTime);
	virtual void checkBoundary();
};

#endif
