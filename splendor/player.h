#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player : public Entity
{
public:
	Point velocity;
	Player();
	void HandlePlayer();
	void controlPlayer(int switcher, float deltaTime);
	virtual ~Player();
	virtual void update(float deltaTime);

private:
	Timer t;
	int speed = 750;
	double sqrt2 = sqrt(2);
};
#endif
