#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player : public Entity
{
public:
	Point velocity;
	Player();
	void handlePlayer();
	void controlPlayer(int switcher, float deltaTime);
	virtual ~Player();
	virtual void update(float deltaTime);
	void killYourself();
	void takeDamage(float deltaTime);

private:
	Timer t;
	int speed;
	double sqrt2 = sqrt(2);
	double health;
};
#endif
