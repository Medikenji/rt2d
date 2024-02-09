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

private:
	// variables
	float _Time;
	Vector2 *_pTargetPosition;
	int _Randomiser;
	float _Speed;

	// functions
	const void goMove(Vector2 playerPos, float deltaTime);
	const void goAccelerate(float deltaTime, Vector2 vectorial, int switcher);
	const void countDown(float countdownTime, float deltaTime);
};

#endif /* ALTPATHENEMY_H */
