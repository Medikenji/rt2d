#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player : public Entity
{
public:
	Player();
	void HandlePlayer(float mx, float my);
	void controlPlayer(int switcher, float deltaTime);
	virtual ~Player();
	virtual void update(float deltaTime);

private:
	Timer t;
	int speed = 750;
	Point velocity;
	double sqrt2 = sqrt(2);
};
#endif
