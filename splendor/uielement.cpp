// uielement.cpp

#include "uielement.h"

UIElement::UIElement(Player *player, float *score, long highscore) : Entity()
{
	_pHealthBar = new HealthBar(player);
	this->addChild(_pHealthBar);
	_pScoreDisplay = new ScoreDisplay(player, score, highscore);
	this->addChild(_pScoreDisplay);
}

UIElement::~UIElement()
{
}

void UIElement::update(float deltaTime)
{
}
