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
	manageHealthBar();
}

void UIElement::manageHealthBar()
{
	PlayerHealth = this->PlayerP->getHealth();
	colorInt = (int)(PlayerHealth * 2.55) + 1;
	this->scale = Point2(((SWIDTH / 2) * PlayerHealth) / 100, 5);
	this->sprite()->color = RGBAColor(-colorInt, colorInt, 0, 255);
}