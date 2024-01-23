#include "player.h"
#include <vectorx.h>
Player::Player() : Splentity()
{
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
	Splentity::update(deltaTime);
	killYourself();
	handlePlayer();
	regenHealth(deltaTime);
}

void Player::controlPlayer(int switcher, float deltaTime)
{
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
	this->speed = 750 * speedMultiplier / 2;
	if (this->velocity.x && this->velocity.y != NULL)
	{
		this->velocity.x /= this->sqrt2;
	}
	this->position += this->velocity;
	this->velocity *= 0;
}

double Player::getHealth()
{
	return (this->health / this->startHealth) * 100;
}

void Player::regenHealth(float deltaTime)
{
	if (this->health < this->startHealth / 4 && this->health > 0)
	{
		health += 0.005 * deltaTime * speedMultiplier;
	}
	else if (this->health < startHealth * 0.75)
	{
		health += 0.0005 * deltaTime * speedMultiplier;
	}
}