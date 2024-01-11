// uielement.cpp

#include "uielement.h"

UIElement::UIElement(Player *player) : Entity()
{
	this->addSprite("assets/healthbar.tga");
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
	this->PlayerHealth = this->PlayerP->getHealth();
	this->colorInt = (int)(this->PlayerHealth * 2.55) + 1;
	this->scale = Point2(((SWIDTH / 2) * this->PlayerHealth) / 100, 2);
	this->sprite()->color = RGBAColor(-this->colorInt, this->colorInt, 0, 255);
}