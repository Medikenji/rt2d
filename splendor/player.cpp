#include "player.h"
#include <vectorx.h>
Player::Player() : Entity()
{
	health = 3;
	speed = 750;
	t.start();
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
		velocity *= 2;
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