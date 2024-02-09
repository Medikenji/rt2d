#include "player.h"
#include <vectorx.h>
Player::Player() : Splentity()
{
	// _pPlayer setuo
	this->health = 1;
	this->position = Vector2(SWIDTH / 2, SHEIGHT / 2);
	this->_startHealth = this->health;
	this->addSprite("assets/_pPlayer.tga");
	this->scale = Vector2(0.1, 0.1);
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	// functions
	Splentity::update(deltaTime);
	killYourself();
	handlePlayer();
	regenHealth(deltaTime);
}

const void Player::controlPlayer(int switcher, float deltaTime)
{
	// allows the _pPlayer to move depending on the switcher val
	switch (switcher)
	{
	case 100:
		this->_Velocity += Point(0, -this->_Speed) * deltaTime;
		break;
	case 110:
		this->_Velocity += Point(0, this->_Speed) * deltaTime;
		break;
	case 120:
		this->_Velocity += Point(-this->_Speed, 0) * deltaTime;
		break;
	case 130:
		this->_Velocity += Point(this->_Speed, 0) * deltaTime;
		break;
	case 140:
		this->_Velocity *= (this->sGameMultiplier / 4) + 1;
		break;
	}
}

const void Player::handlePlayer()
{
	// allows _pPlayer to not go faster when moving on the X and Y axis
	this->_Speed = 750 * sGameMultiplier / 2;
	if (this->_Velocity.x && this->_Velocity.y != NULL)
	{
		this->_Velocity.x /= this->_Sqrt2;
	}

	// manage and reset movement
	this->position += this->_Velocity;
	this->_Velocity *= 0;
}

double Player::getHealth() const
{
	// get setter for _pPlayer health
	return (this->health / this->_startHealth) * 100;
}

const void Player::regenHealth(float deltaTime)
{
	// regens health depending on how much hp is left
	if (this->health < this->_startHealth / 4 && this->health > 0)
	{
		health += 0.005 * deltaTime * sGameMultiplier;
	}
	else if (this->health < _startHealth * 0.99)
	{
		health += 0.001 * deltaTime * sGameMultiplier;
	}
}