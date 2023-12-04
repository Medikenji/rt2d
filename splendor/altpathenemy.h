// altpathenemy.h

#ifndef ALTPATHENEMY_H
#define ALTPATHENEMY_H

#include "enemy.h"

class AltPathEnemy : public Enemy
{
public:
	void goMove(Point playerPos, float deltaTime);
	void goAccelerate();
	AltPathEnemy();
	virtual ~AltPathEnemy();

private:
	Vector2 velocity;
	float speed;
};

#endif /* ALTPATHENEMY_H */
