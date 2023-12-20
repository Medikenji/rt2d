// uielement.cpp

#include "uielement.h"

UIElement::UIElement(Player *player) : Entity()
{
	this->addSprite("assets/healthbar.tga");
	this->scale = Point2((SWIDTH / 2), 5);
	this->sprite()->pivot = Point2(0, 0);
	this->sprite()->color = RGBAColor(0, 255, 0, 255);
	this->position = Point2(0, 0);
	this->PlayerP = player;
}

UIElement::~UIElement()
{
}

void UIElement::update(float deltaTime)
{
	PlayerHealth = this->PlayerP->getHealth();
	this->scale = Point2((SWIDTH / 2) * PlayerHealth, 5);
	this->sprite()->color = RGBAColor(0, 255, 0, 255);
}