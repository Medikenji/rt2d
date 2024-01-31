#ifndef PLAYER_H
#define PLAYER_H

#include "splentity.h"

class Player : public Splentity
{
public:
	// variables
	Point velocity;

	// functions
	Player();
	virtual ~Player();
	double getHealth();
	void controlPlayer(int switcher, float deltaTime);

private:
	// variables
	Timer t;
	int speed;
	double sqrt2 = sqrt(2);
	double startHealth;

	// functions
	virtual void update(float deltaTime);
	void handlePlayer();
	void regenHealth(float deltaTime);
};
#endif
