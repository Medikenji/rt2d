#include <fstream>
#include <sstream>
#include <color.h>
#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	t.start();
	altEnemy = new AltPathEnemy(&enemyTarget);
	altEnemy->position = Point2(SWIDTH / 5, SHEIGHT / 5);
	straightEnemy = new LinePathEnemy(&enemyTarget);
	straightEnemy->position = Point2(SWIDTH / 3, SHEIGHT / 3);
	player = new Player();
	player->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(player);
	this->addChild(altEnemy);
	this->addChild(straightEnemy);
}

GameScene::~GameScene()
{
	this->removeChild(player);
	this->removeChild(altEnemy);
	this->removeChild(straightEnemy);
	delete player;
	delete altEnemy;
	delete straightEnemy;
}

void GameScene::update(float deltaTime)
{
	enemyTarget = player->position;
	getMouse();
	exitGame();
	controlPlayer(deltaTime);
	drawLine(mx, my);
}

void GameScene::getMouse()
{
	mx = input()->getMouseX();
	my = input()->getMouseY();
}

void GameScene::exitGame()
{
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}
}

void GameScene::controlPlayer(float deltaTime)
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

void GameScene::drawLine(float mx, float my)
{
	ddClear();
	ddLine(player->position.x, player->position.y, mx, my, player->sprite()->color);
}