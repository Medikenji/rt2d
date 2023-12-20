#include "player.h"
#include <vectorx.h>
Player::Player() : Splentity()
{
	health = 1;
	startHealth = health;
	speed = 750 * speedMultiplier / 2;
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
}

void Player::controlPlayer(int switcher, float deltaTime)
{
	switch (switcher)
	{
	case 1:
		velocity += Point(0, -speed) * deltaTime;
		break;
	case 2:
		velocity += Point(0, speed) * deltaTime;
		break;
	case 3:
		velocity += Point(-speed, 0) * deltaTime;
		break;
	case 4:
		velocity += Point(speed, 0) * deltaTime;
		break;
	case 5:
		velocity *= (speedMultiplier / 4) + 1;
		break;
	}
}

void Player::handlePlayer()
{
	if (velocity.x && velocity.y != NULL)
	{
		velocity.x /= sqrt2;
		velocity.y /= sqrt2;
	}
	this->position += velocity;
	velocity *= 0;
}

void Player::takeDamage(float deltaTime)
{
	health -= 1 * deltaTime;
}

void Player::killYourself()
{
	if (health <= 0 && this != nullptr)
	{
		this->parent()->removeChild(this);
	}
}

double Player::getHealth()
{
	return this->health / startHealth;
}