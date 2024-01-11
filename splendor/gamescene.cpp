#include <fstream>
#include <sstream>
#include <color.h>
#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	t.start();
	altPathEnemies = std::vector<AltPathEnemy *>();
	linePathEnemies = std::vector<LinePathEnemy *>();
	CreateScoreT();
	createSingleEntities();
	createAltPathEnemies(5);
	createLinePathEnemies(1);
	createStoicEnemies(5);
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
		player->controlPlayer(Up, deltaTime);
	}
	if (input()->getKey(KeyCode::S))
	{
		player->controlPlayer(Down, deltaTime);
	}
	if (input()->getKey(KeyCode::A))
	{
		player->controlPlayer(Left, deltaTime);
	}
	if (input()->getKey(KeyCode::D))
	{
		player->controlPlayer(Right, deltaTime);
	}
	if (input()->getKey(KeyCode::LeftShift))
	{
		player->controlPlayer(Boost, deltaTime);
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

void GameScene::checkCol(float deltaTime)
{
	if (player->position.x > SWIDTH || player->position.x < 0 || player->position.y > SHEIGHT || player->position.y < 0)
	{
		player->takeDamage(deltaTime);
	}

	for (const auto AltPathEnemy : altPathEnemies)
	{
		if (AltPathEnemy->position.x > SWIDTH || AltPathEnemy->position.y > SHEIGHT)
		{
			AltPathEnemy->position = Vector2(rand() % SWIDTH, -SHEIGHT);
		}
		if (col(AltPathEnemy, player))
		{
			player->takeDamage(deltaTime);
		}
		if (mouseCol(AltPathEnemy, mx, my))
		{
			AddScore(deltaTime, 50);
			HitEnemy = true;
		}
	}
	for (const auto LinePathEnemy : linePathEnemies)
	{
		if (LinePathEnemy->position.x > SWIDTH || LinePathEnemy->position.y > SHEIGHT)
		{
			LinePathEnemy->position = Vector2(rand() % SWIDTH, -SHEIGHT);
		}
		if (col(LinePathEnemy, player))
		{
			player->takeDamage(deltaTime);
		}
		if (mouseCol(LinePathEnemy, mx, my))
		{
			AddScore(deltaTime, 75);
			HitEnemy = true;
		}
	}
	for (const auto stoicEnemy : stoicEnemies)
	{
		if (stoicEnemy->position.x > SWIDTH || stoicEnemy->position.y > SHEIGHT)
		{
			stoicEnemy->position = Vector2(rand() % SWIDTH, -SHEIGHT);
		}
		if (col(stoicEnemy, player))
		{
			player->takeDamage(deltaTime);
		}
		if (mouseCol(stoicEnemy, mx, my))
		{
			AddScore(deltaTime, 1);
			HitEnemy = true;
		}
	}
}

bool GameScene::col(Enemy *enemy, Player *player)
{
	return (enemy->position.x < player->position.x + player->sprite()->size.x * player->scale.x &&
					enemy->position.x + enemy->sprite()->size.x * enemy->scale.x > player->position.x &&
					enemy->position.y < player->position.y + player->sprite()->size.y * player->scale.y &&
					enemy->position.y + enemy->sprite()->size.y * enemy->scale.y > player->position.y);
}

bool GameScene::mouseCol(Enemy *enemy, int mx, int my)
{
	return (abs((int)enemy->position.x - mx) < 10) && (abs((int)enemy->position.y - my) < 10);
}

void GameScene::createSingleEntities()
{
	player = new Player();
	this->addChild(player);
	UIelement = new UIElement(player);
	this->addChild(UIelement);
}

void GameScene::AddScore(float deltaTime, int amount)
{
	if (IsAlive)
	{
		score += amount * deltaTime * Splentity::speedMultiplier;
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