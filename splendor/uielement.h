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

private:
	Player *PlayerP;
	int a;
	int b;

protected:
	float PlayerHealth;
};

#endif /* UIELEMENT_H */
