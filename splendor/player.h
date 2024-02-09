#ifndef PLAYER_H
#define PLAYER_H

#include "splentity.h"

class Player : public Splentity
{
public:
	// variables
	Point _Velocity;

	// functions
	Player();
	virtual ~Player();
	double getHealth() const;
	const void controlPlayer(int switcher, float deltaTime);

private:
	// variables
	Timer _T;
	int _Speed;
	double _Sqrt2 = sqrt(2);
	double _startHealth;

	// functions
	virtual void update(float deltaTime);
	const void handlePlayer();
	const void regenHealth(float deltaTime);
};
#endif
