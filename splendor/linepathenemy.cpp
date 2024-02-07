#include "linepathenemy.h"

LinePathEnemy::LinePathEnemy(Vector2 *targetEntity) : Enemy()
{
	// setup enemy
	this->health = 100;
	this->_pTargetPosition = targetEntity;
	this->scale = Vector2(0.1, 0.1);
	this->sprite()->color = RGBAColor(255, 0, 0, 255);
	this->pointAmount = 125;
	this->damageAmount = 1;
}

LinePathEnemy::~LinePathEnemy()
{
}

void LinePathEnemy::update(float deltaTime)
{
	// functions
	Enemy::update(deltaTime);
	goMove(*_pTargetPosition, deltaTime);
	this->pointAmount = 83 * sGameMultiplier * 1.5;
}

void LinePathEnemy::goMove(Point playerPos, float deltaTime)
{
	// updates the _Speed
	_Speed = 350 * sGameMultiplier;

	// makes enemy point and go to _pPlayer
	Vector2 Vectorial = playerPos - this->position;
	Vectorial.normalize();
	_Velocity += Vectorial * _Speed * deltaTime;
	this->position += _Velocity;

	// resets enemy velocity
	_Velocity *= 0;
}