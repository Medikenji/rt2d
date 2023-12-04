#include <fstream>
#include <sstream>
#include <color.h>
#include "myscene.h"
Point EnemyVelocity;
MyScene::MyScene() : Scene()
{
	t.start();
	altEnemy = new AltPathEnemy();
	altEnemy->position = Point2(SWIDTH / 5, SHEIGHT / 5);
	straightEnemy = new LinePathEnemy();
	straightEnemy->position = Point2(SWIDTH / 3, SHEIGHT / 3);
	player = new Player();
	player->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(player);
	this->addChild(altEnemy);
	this->addChild(straightEnemy);
}

MyScene::~MyScene()
{
	this->removeChild(player);
	this->removeChild(altEnemy);
	delete player;
	delete altEnemy;
}

void MyScene::update(float deltaTime)
{
	getMouse();
	exitGame();
	controlPlayer(deltaTime);
	player->HandlePlayer(mx, my);
	altEnemy->goMove(player->position, deltaTime);
	straightEnemy->goMove(player->position, deltaTime);
	drawLine(mx, my);
}
void MyScene::getMouse()
{
	mx = input()->getMouseX();
	my = input()->getMouseY();
}

void MyScene::exitGame()
{
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}
}

void MyScene::controlPlayer(float deltaTime)
{
	if (input()->getKey(KeyCode::W))
	{
		player->controlPlayer(1, deltaTime);
	}
	if (input()->getKey(KeyCode::S))
	{
		player->controlPlayer(2, deltaTime);
	}
	if (input()->getKey(KeyCode::A))
	{
		player->controlPlayer(3, deltaTime);
	}
	if (input()->getKey(KeyCode::D))
	{
		player->controlPlayer(4, deltaTime);
	}
	if (input()->getKey(KeyCode::LeftShift))
	{
		player->controlPlayer(5, deltaTime);
	}
}

void MyScene::drawLine(float mx, float my)
{
	ddClear();
	ddLine(player->position.x, player->position.y, mx, my, player->sprite()->color);
}
