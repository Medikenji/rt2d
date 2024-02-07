// uielement.h

#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <entity.h>
#include <text.h>
#include "player.h"
#include "healthbar.h"
#include "scoredisplay.h"

class UIElement : public Entity
{
public:
	// functions
	UIElement(Player *player, float *score, long highscore);
	virtual ~UIElement();

private:
	// variables
	HealthBar *_pHealthBar;
	ScoreDisplay *_pScoreDisplay;

	// functions
	virtual void update(float deltaTime);
};

#endif /* UIELEMENT_H */
