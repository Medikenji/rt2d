#include "player.h"
#include <vectorx.h>
Player::Player() : Splentity()
{
	// player setuo
	this->health = 1;
	this->position = Vector2(SWIDTH / 2, SHEIGHT / 2);
	this->startHealth = this->health;
	this->addSprite("assets/player.tga");
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

void Player::controlPlayer(int switcher, float deltaTime)
{
	// allows the player to move depending on the switcher val
	switch (switcher)
	{
	case 100:
		this->velocity += Point(0, -this->speed) * deltaTime;
		break;
	case 110:
		this->velocity += Point(0, this->speed) * deltaTime;
		break;
	case 120:
		this->velocity += Point(-this->speed, 0) * deltaTime;
		break;
	case 130:
		this->velocity += Point(this->speed, 0) * deltaTime;
		break;
	case 140:
		this->velocity *= (this->speedMultiplier / 4) + 1;
		break;
	}
}

void Player::handlePlayer()
{
	// allows player to not go faster when moving on the X and Y axis
	this->speed = 750 * speedMultiplier / 2;
	if (this->velocity.x && this->velocity.y != NULL)
	{
		this->velocity.x /= this->sqrt2;
	}

	// manage and reset movement
	this->position += this->velocity;
	this->velocity *= 0;
}

double Player::getHealth()
{
	// get setter for player health
	return (this->health / this->startHealth) * 100;
}

void Player::regenHealth(float deltaTime)
{
	// regens health depending on how much hp is left
	if (this->health < this->startHealth / 4 && this->health > 0)
	{
		health += 0.005 * deltaTime * speedMultiplier;
	}
	else if (this->health < startHealth * 0.75)
	{
		health += 0.001 * deltaTime * speedMultiplier;
	}
}