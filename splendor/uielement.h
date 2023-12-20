// uielement.h

#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <entity.h>
#include "player.h"

class UIElement : public Entity
{
public:
	UIElement(Player *player);
	virtual ~UIElement();
	void update(float deltaTime);
	void manageHealthBar();

private:
	Player *PlayerP;
	int colorInt;

protected:
	float PlayerHealth;
};

#endif /* UIELEMENT_H */
