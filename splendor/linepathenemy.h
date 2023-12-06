// linepathenemy.h

#ifndef LINEPATHENEMY_H
#define LINEPATHENEMY_H

#include "enemy.h"

class LinePathEnemy : public Enemy
{
public:
	LinePathEnemy(Vector2 *targetEntity);
	virtual ~LinePathEnemy();
	virtual void update(float deltaTime);
	void goMove(Point playerPos, float deltaTime);

private:
	Vector2 *targetPosition;
	int speed;
	Vector2 velocity;
};

#endif /* LINEPATHENEMY_H */
