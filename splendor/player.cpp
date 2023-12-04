#include "player.h"
#include <vectorx.h>
Player::Player() : Entity()
{
	t.start();
	this->addSprite("assets/player.tga");
	this->scale = Point2(0.1, 0.1);
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
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

void Player::HandlePlayer(float mx, float my)
{
	if (velocity.x && velocity.y != NULL)
	{
		velocity.x /= sqrt2;
		velocity.y /= sqrt2;
	}
	this->position += velocity;
	velocity *= 0;
	Vector2 diff = Vector2(mx, my) - this->position;
	this->rotation.z = diff.getAngle();
}