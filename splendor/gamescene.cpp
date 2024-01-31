#include <fstream>
#include <sstream>
#include <color.h>
#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	// starts timer on setup
	t.start();

	// creates all entities that need to exist on startup
	createSingleEntities();

	// creates and starts timer
	timer = new Timer();
	TimerSetup();
}

GameScene::~GameScene()
{
}

void GameScene::update(float deltaTime)
{
	// gets location of mouse
	mx = input()->getMouseX();
	my = input()->getMouseY();

	// resets the enemy hit val every frame
	HitEnemy = false;

	// checks if player is alive
	IsAlive = player->GetLivingStatus();

	// sets the target for enemies
	enemyTarget = player->position;

	// functions
	controlPlayer(deltaTime);
	checkCol(deltaTime);
	drawLine(mx, my);
	ManageScoreT();
	ManageSpawns();
}

void GameScene::controlPlayer(float deltaTime)
{
	// enables quitting the game
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}

	// player movement controlls
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
	// clears the line before another one gets drawn
	ddClear();

	// draws line after checking if an enemy has been hit for the right color
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
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		_enemies.push_back(new AltPathEnemy(&enemyTarget));
	}
	for (const auto AltPathEnemy : _enemies)
	{
		this->addChild(AltPathEnemy);
	}
}

void GameScene::createLinePathEnemies(int amount)
{
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		_enemies.push_back(new LinePathEnemy(&enemyTarget));
	}
	for (const auto LineEnemy : _enemies)
	{
		this->addChild(LineEnemy);
	}
}

void GameScene::createStoicEnemies(int amount)
{
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		_enemies.push_back(new StoicEnemy());
	}
	for (const auto StoicEnemy : _enemies)
	{
		this->addChild(StoicEnemy);
	}
}

void GameScene::createStraightEnemies(int amount)
{
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		_enemies.push_back(new StraightEnemy());
	}
	for (const auto StraightEnemy : _enemies)
	{
		this->addChild(StraightEnemy);
	}
}

void GameScene::checkCol(float deltaTime)
{
	// checks if player is outside of screen, if true the player takes damage
	if (player->position.x > SWIDTH || player->position.x < 0 || player->position.y > SHEIGHT || player->position.y < 0)
	{
		player->takeDamage(deltaTime);
	}

	// checks if any of the enemies touch the player
	for (auto Enemy : _enemies)
	{
		// if the col() function detects a run the player->takeDamage() function
		if (col(Enemy, player))
		{
			player->takeDamage(deltaTime);
		}

		// if the mouch touches an enemy turn HitEnemy to true and add score per second
		if (mouseCol(Enemy, mx, my))
		{
			AddScore(deltaTime, Enemy->pointAmount);
			HitEnemy = true;
		}
	}
}

bool GameScene::col(Enemy *enemy, Player *player)
{
	// check if the difference between the player and enemy position is less than a dynamic value
	return (abs(enemy->position.x - player->position.x) < (player->sprite()->size.x * player->scale.x + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - player->position.y) < (player->sprite()->size.y * player->scale.y + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

bool GameScene::mouseCol(Enemy *enemy, float mx, float my)
{
	// check if the difference between the mouse and enemy position is less than a dynamic value
	return (abs(enemy->position.x - mx) < (10 + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - my) < (10 + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

void GameScene::createSingleEntities()
{
	// creates player
	player = new Player();
	this->addChild(player);

	// creates ui
	UIelement = new UIElement(player);
	this->addChild(UIelement);
	CreateScoreT();

	// creates starter enemy
	createLinePathEnemies(1);
}

void GameScene::AddScore(float deltaTime, int amount)
{
	// adds a variable score when player is alive and called
	if (IsAlive)
	{
		score += amount * deltaTime * (Splentity::speedMultiplier * 1.2);
		presentScore = (int)score;
	}
}

void GameScene::CreateScoreT()
{
	// sets score to 0
	score = 0;
	presentScore = 0;

	// creates score text
	this->text = new Text();
	this->text->position = Vector2(20, SHEIGHT - 20);
	this->addChild(this->text);
	this->text->scale = Vector2(0.75, 0.75);
}

void GameScene::ManageScoreT()
{
	// updates te score text
	if (IsAlive)
	{
		this->text->message(std::to_string(presentScore));
	}
	else
	{
		this->text->position = Vector2(SWIDTH / 10, SHEIGHT / 2);
		this->text->scale = Vector2(1, 1);
		this->text->message("Game Over, your score is:	" + std::to_string(presentScore), RED);
	}
}

void GameScene::ManageSpawns()
{
	if (timer->seconds() >= spawnRate)
	{
		// increases the spawnrate each time enemies spawn
		spawnRate += 0.75;

		// starts the timer
		timer->start();

		// creates enemies
		createAltPathEnemies(rand() % enemyAmount);
		createStoicEnemies(1);
		createStraightEnemies((rand() % 2) + 1);
		enemyAmount++;
	}
}

void GameScene::TimerSetup()
{
	// setups timer with 5 second spawn delay
	spawnRate = 5;
	timer->start();
}
