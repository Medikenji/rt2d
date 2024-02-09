// healthbar.h

#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <entity.h>
#include "player.h"

class HealthBar : public Entity
{
public:
	HealthBar(Player *player);
	virtual ~HealthBar();

private:
	// variables
	Player *_pPlayer;
	int _colorInt;
	float _playerHealth;
	bool _damageState;

	// functions
	virtual void update(float deltaTime);
	const void manageHealthBar();
};

#endif /* HEALTHBAR_H */
