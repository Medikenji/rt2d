#include <fstream>
#include <sstream>
#include <color.h>
#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	t.start();
	createSingleEntities();
	timer = new Timer();
	TimerSetup();
}

GameScene::~GameScene()
{
	this->removeChild(player);
	delete player;
}

void GameScene::update(float deltaTime)
{
	HitEnemy = false;
	IsAlive = player->GetLivingStatus();
	getMouse();
	enemyTarget = player->position;
	exitGame();
	controlPlayer(deltaTime);
	checkCol(deltaTime);
	drawLine(mx, my);
	ManageScoreT();
	ManageSpawns();
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
		player->controlPlayer(UP, deltaTime);
	}
	if (input()->getKey(KeyCode::S))
	{
		player->controlPlayer(DOWN, deltaTime);
	}
	if (input()->getKey(KeyCode::A))
	{
		player->controlPlayer(LEFT, deltaTime);
	}
	if (input()->getKey(KeyCode::D))
	{
		player->controlPlayer(RIGHT, deltaTime);
	}
	if (input()->getKey(KeyCode::LeftShift))
	{
		player->controlPlayer(BOOST, deltaTime);
	}
}

void GameScene::drawLine(float mx, float my)
{
	ddClear();
	if (HitEnemy == false)
	{
		ddLine(player->position.x, player->position.y, mx, my, WHITE);
		ddCircle(mx, my, 10, WHITE);
	}
	else
	{
		ddLine(player->position.x, player->position.y, mx, my, GREEN);
		ddCircle(mx, my, 10, GREEN);
	}
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

void GameScene::createStoicEnemies(int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		stoicEnemies.push_back(new StoicEnemy());
	}
	for (const auto stoicEnemy : stoicEnemies)
	{
		this->addChild(stoicEnemy);
	}
}

void GameScene::createStraightEnemies(int amount)
{
	for (size_t i = 0; i < amount; i++)
	{
		straightEnemies.push_back(new StraightEnemy());
	}
	for (const auto straightEnemy : straightEnemies)
	{
		this->addChild(straightEnemy);
	}
}

void GameScene::checkCol(float deltaTime)
{
	if (player->position.x > SWIDTH || player->position.x < 0 || player->position.y > SHEIGHT || player->position.y < 0)
	{
		player->takeDamage(deltaTime);
	}
	for (const auto AltPathEnemy : altPathEnemies)
	{
		if (col(AltPathEnemy, player))
		{
			player->takeDamage(deltaTime);
		}
		if (mouseCol(AltPathEnemy, mx, my))
		{
			AddScore(deltaTime, 5);
			HitEnemy = true;
		}
	}
	for (const auto LinePathEnemy : linePathEnemies)
	{
		if (col(LinePathEnemy, player))
		{
			player->takeDamage(deltaTime);
		}
		if (mouseCol(LinePathEnemy, mx, my))
		{
			AddScore(deltaTime, 125);
			HitEnemy = true;
		}
	}
	for (const auto stoicEnemy : stoicEnemies)
	{
		if (col(stoicEnemy, player))
		{
			player->takeDamage(deltaTime);
		}
		if (mouseCol(stoicEnemy, mx, my))
		{
			AddScore(deltaTime, 5);
			HitEnemy = true;
		}

		for (const auto straightEnemy : straightEnemies)
		{
			if (col(straightEnemy, player))
			{
				player->takeDamage(deltaTime * 0.5);
			}
			if (mouseCol(straightEnemy, mx, my))
			{
				AddScore(deltaTime, 10);
				HitEnemy = true;
			}
		}
	}
}

bool GameScene::col(Enemy *enemy, Player *player)
{
	return (abs(enemy->position.x - player->position.x) < (player->sprite()->size.x * player->scale.x + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - player->position.y) < (player->sprite()->size.y * player->scale.y + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

bool GameScene::mouseCol(Enemy *enemy, float mx, float my)
{
	return (abs(enemy->position.x - mx) < (10 + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - my) < (10 + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

void GameScene::createSingleEntities()
{
	player = new Player();
	this->addChild(player);
	UIelement = new UIElement(player);
	this->addChild(UIelement);
	createLinePathEnemies(1);
	CreateScoreT();
}

void GameScene::AddScore(float deltaTime, int amount)
{
	if (IsAlive)
	{
		score += amount * deltaTime * (Splentity::speedMultiplier * 1.2);
		presentScore = (int)score;
	}
}

void GameScene::CreateScoreT()
{
	score = 0;
	presentScore = 0;
	this->text = new Text();
	this->text->position = Vector2(20, SHEIGHT - 20);
	this->addChild(this->text);
	this->text->scale = Vector2(0.75, 0.75);
}

void GameScene::ManageScoreT()
{
	this->text->message(std::to_string(presentScore));
}

void GameScene::ManageSpawns()
{
	if (timer->seconds() >= spawnRate)
	{
		spawnRate += 0.75;
		timer->start();
		createAltPathEnemies(rand() % enemyAmount);
		createStoicEnemies(1);
		createStraightEnemies((rand() % 2) + 1);
		enemyAmount++;
	}
}

void GameScene::TimerSetup()
{
	spawnRate = 5;
	timer->start();
}
