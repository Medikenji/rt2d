// altpathenemy.h

#ifndef ALTPATHENEMY_H
#define ALTPATHENEMY_H

#include "enemy.h"

class AltPathEnemy : public Enemy
{
public:
	AltPathEnemy(Vector2 *targetEntity);
	virtual ~AltPathEnemy();
	void update(float deltaTime);
	void goMove(Point2 playerPos, float deltaTime);
	void goAccelerate(float deltaTime, Vector2 vectorial, bool switcher);

private:
	Vector2 *targetPosition;
	Vector2 velocity;
	float speed;
};

#endif /* ALTPATHENEMY_H */
