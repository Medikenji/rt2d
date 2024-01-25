// uielement.cpp

#include "uielement.h"

UIElement::UIElement(Player *player) : Entity()
{
	// UI setup
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
	std::cout << "this:   " << this->PlayerHealth << std::endl;
	std::cout << "player: " << this->PlayerP->getHealth() << std::endl;
}

void UIElement::manageHealthBar()
{
	// converts the playerhealth into the size of the healtbar
	if (this->PlayerHealth <= this->PlayerP->getHealth())
	{
		DamageState = true;
	}
	this->PlayerHealth = this->PlayerP->getHealth();
	std::cout << DamageState << std::endl;
	this->colorInt = (int)(this->PlayerHealth * 2.55) + 1;
	// changes color depending on situation
	this->sprite()->color = RGBAColor(-this->colorInt, this->colorInt, 0, 255);
	if (DamageState)
	{
		this->sprite()->color = RGBAColor(-this->colorInt, this->colorInt, 0, 255);
		this->scale = Vector2(((SWIDTH / 2) * this->PlayerHealth) / 100, 2);
	}
	else
	{
		this->sprite()->color = RGBAColor(255, 0, 0, 255);
		this->scale = Vector2(((SWIDTH / 2) * this->PlayerHealth) / 100, 2.5);
	}
	DamageState = false;
}