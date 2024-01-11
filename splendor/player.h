#ifndef PLAYER_H
#define PLAYER_H

#include "splentity.h"

class Player : public Splentity
{
public:
	Point velocity;
	Player();
	void handlePlayer();
	void controlPlayer(int switcher, float deltaTime);
	virtual ~Player();
	virtual void update(float deltaTime);
	double getHealth();
	void regenHealth(float deltaTime);

private:
	Timer t;
	int speed;
	double sqrt2 = sqrt(2);
	double startHealth;
};
#endif
