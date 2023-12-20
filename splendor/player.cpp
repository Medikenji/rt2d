#include "player.h"
#include <vectorx.h>
Player::Player() : Splentity()
{
	this->health = 1;
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->startHealth = this->health;
	this->speed = 750 * this->speedMultiplier / 2;
	this->addSprite("assets/player.tga");
	this->scale = Point2(0.1, 0.1);
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	killYourself();
	handlePlayer();
	regenHealth(deltaTime);
}

void Player::controlPlayer(int switcher, float deltaTime)
{
	switch (switcher)
	{
	case 1:
		this->velocity += Point(0, -this->speed) * deltaTime;
		break;
	case 2:
		this->velocity += Point(0, this->speed) * deltaTime;
		break;
	case 3:
		this->velocity += Point(-this->speed, 0) * deltaTime;
		break;
	case 4:
		this->velocity += Point(this->speed, 0) * deltaTime;
		break;
	case 5:
		this->velocity *= (this->speedMultiplier / 4) + 1;
		break;
	}
}

void Player::handlePlayer()
{
	if (this->velocity.x && this->velocity.y != NULL)
	{
		this->velocity.x /= this->sqrt2;
		this->velocity.y /= this->sqrt2;
	}
	this->position += this->velocity;
	this->velocity *= 0;
}

void Player::takeDamage(float deltaTime)
{
	this->health -= 1 * deltaTime;
}

void Player::killYourself()
{
	if (this->health <= 0 && this != nullptr)
	{
		this->parent()->removeChild(this);
	}
}

double Player::getHealth()
{
	return (this->health / this->startHealth) * 100;
}

void Player::regenHealth(float deltaTime)
{
	if (health < startHealth / 4 && health > 0)
	{
		health += 0.005 * deltaTime;
	}
}