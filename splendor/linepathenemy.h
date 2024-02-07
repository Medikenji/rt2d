// linepathenemy.h

#ifndef LINEPATHENEMY_H
#define LINEPATHENEMY_H

#include "enemy.h"

class LinePathEnemy : public Enemy
{
public:
	LinePathEnemy(Vector2 *targetEntity);
	virtual ~LinePathEnemy();

private:
	// variables
	Vector2 *_pTargetPosition;
	int _Speed;
	Vector2 _Velocity;

	// functions
	virtual void update(float deltaTime);
	void goMove(Point playerPos, float deltaTime);
};

#endif /* LINEPATHENEMY_H */
