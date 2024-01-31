// uielement.h

#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <entity.h>
#include <text.h>
#include "player.h"

class UIElement : public Entity
{
public:
	// functions
	UIElement(Player *player);
	virtual ~UIElement();

private:
	// variables
	Player *PlayerP;
	int colorInt;
	float PlayerHealth;
	bool DamageState;

	// functions
	void update(float deltaTime);
	void manageHealthBar();
};

#endif /* UIELEMENT_H */
