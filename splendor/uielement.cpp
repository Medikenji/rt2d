// uielement.cpp

#include "uielement.h"

UIElement::UIElement(Player *player) : Entity()
{
	this->addSprite("assets/healthbar.tga");
	this->sprite()->pivot = Vector2(0, 0);
	this->sprite()->color = RGBAColor(0, 255, 0, 255);
	this->position = Vector2(0, 0);
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
	this->scale = Vector2(((SWIDTH / 2) * this->PlayerHealth) / 100, 2);
	this->sprite()->color = RGBAColor(-this->colorInt, this->colorInt, 0, 255);
}