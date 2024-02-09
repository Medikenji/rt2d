// healthbar.cpp

#include "healthbar.h"

HealthBar::HealthBar(Player *_pPlayer) : Entity()
{
	// HealthBar setup
	this->addSprite("assets/healthbar.tga");
	this->sprite()->pivot = Vector2(0, 0);
	this->sprite()->color = RGBAColor(0, 255, 0, 255);
	this->position = Vector2(0, 0);
	this->_pPlayer = _pPlayer;
}

HealthBar::~HealthBar()
{
}

void HealthBar::update(float deltaTime)
{
	manageHealthBar();
}

const void HealthBar::manageHealthBar()
{
	// converts the playerhealth into the size of the healtbar
	if (static_cast<float>(static_cast<int>(this->_playerHealth * 10)) / 10 <= static_cast<float>(static_cast<int>(this->_pPlayer->getHealth() * 10)) / 10)
	{
		_damageState = true;
	}
	this->_playerHealth = this->_pPlayer->getHealth();
	this->_colorInt = (int)(this->_playerHealth * 2.55) + 1;
	// changes color depending on situation
	this->sprite()->color = RGBAColor(-this->_colorInt, this->_colorInt, 0, 255);
	if (_damageState)
	{
		this->sprite()->color = RGBAColor(-this->_colorInt, this->_colorInt, 0, 255);
		this->scale = Vector2(((SWIDTH / 2) * this->_playerHealth) / 100, 2);
	}
	else
	{
		this->sprite()->color = RGBAColor(255, 0, 0, 255);
		this->scale = Vector2(((SWIDTH / 2) * this->_playerHealth) / 100, 2);
	}
	_damageState = false;
}
