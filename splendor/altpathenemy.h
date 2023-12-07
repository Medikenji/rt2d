// altpathenemy.h

#ifndef ALTPATHENEMY_H
#define ALTPATHENEMY_H
#include <time.h>
#include "enemy.h"

class AltPathEnemy : public Enemy
{
public:
	AltPathEnemy(Vector2 *targetEntity);
	virtual ~AltPathEnemy();
	void update(float deltaTime);
	void goMove(Point2 playerPos, float deltaTime);
	void goAccelerate(float deltaTime, Vector2 vectorial, int switcher);
	void countDown(float countdownTime, float deltaTime);

private:
	float time;
	Vector2 *targetPosition;
	Vector2 velocity;
	int randomiser;
	float speed;
};

#endif /* ALTPATHENEMY_H */
