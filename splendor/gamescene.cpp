#include <fstream>
#include <sstream>
#include <color.h>
#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	t.start();
	player = new Player();
	player->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(player);
	altPathEnemies = std::vector<AltPathEnemy *>();
	linePathEnemies = std::vector<LinePathEnemy *>();
	createAltPathEnemies(100);
	createLinePathEnemies(100);
}

GameScene::~GameScene()
{
	this->removeChild(player);
	delete player;
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

void GameScene::createAltPathEnemies(int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		altPathEnemies.push_back(new AltPathEnemy(&enemyTarget));
	}
	for (const auto altEnemy : altPathEnemies)
	{
		this->addChild(altEnemy);
	}
}

void GameScene::createLinePathEnemies(int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		linePathEnemies.push_back(new LinePathEnemy(&enemyTarget));
	}
	for (const auto lineEnemy : linePathEnemies)
	{
		this->addChild(lineEnemy);
	}
}