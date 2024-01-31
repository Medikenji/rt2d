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
	Vector2 *targetPosition;
	int speed;
	Vector2 velocity;

	// functions
	virtual void update(float deltaTime);
	void goMove(Point playerPos, float deltaTime);
};

#endif /* LINEPATHENEMY_H */
