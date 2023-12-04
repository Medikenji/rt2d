// linepathenemy.h

#ifndef LINEPATHENEMY_H
#define LINEPATHENEMY_H

#include "enemy.h"

class LinePathEnemy : public Enemy
{
public:
	void goMove(Point playerPos, float deltaTime);
	LinePathEnemy();
	virtual ~LinePathEnemy();

private:
	int speed;
	Vector2 velocity;
};

#endif /* LINEPATHENEMY_H */
