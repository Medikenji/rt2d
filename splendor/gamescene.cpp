#include "gamescene.h"

GameScene::GameScene() : Scene()
{
	this->_Score = 0;
	// starts timer on setup
	this->_T.start();

	// creates and starts timer
	this->_pTimer = new Timer();
	timerSetup();
	// creates all entities that need to exist on startup
	setupGame();
}

GameScene::~GameScene()
{
}

// runs every frame
void GameScene::update(float deltaTime)
{
	updateFunctions();
	controlPlayer(deltaTime);
	checkCol(deltaTime);
	drawLine(this->_mouseX, this->_mouseY, deltaTime);
	saveScore(this->_Score);
	manageSpawns();
}

// small things that need to be called every frame
const void GameScene::updateFunctions()
{
	// gets location of mouse
	this->_mouseX = input()->getMouseX();
	this->_mouseY = input()->getMouseY();

	// resets the enemy hit val every frame
	this->_hitEnemy = false;

	// checks if player is alive
	this->_playerIsAlive = this->_pPlayer->getLivingStatus();

	// sets the target for enemies
	this->_enemyTarget = this->_pPlayer->position;
}

// calls player controls through inputs
const void GameScene::controlPlayer(float deltaTime)
{
	// enables quitting the game
	if (input()->getKeyUp(KeyCode::Escape))
		this->stop();

	// player movement controlls
	if (input()->getKey(KeyCode::W))
		this->_pPlayer->controlPlayer(UP, deltaTime);
	if (input()->getKey(KeyCode::S))
		this->_pPlayer->controlPlayer(DOWN, deltaTime);
	if (input()->getKey(KeyCode::A))
		this->_pPlayer->controlPlayer(LEFT, deltaTime);
	if (input()->getKey(KeyCode::D))
		this->_pPlayer->controlPlayer(RIGHT, deltaTime);
	if (input()->getKey(KeyCode::LeftShift))
		this->_pPlayer->controlPlayer(BOOST, deltaTime);
}

// draws line from player through mouse depending on scenario
const void GameScene::drawLine(float mouseX, float mouseY, float deltaTime)
{
	// clears the line before another one gets drawn
	ddClear();

	// draws line after checking if an enemy has been hit for the right color
	if (this->_hitEnemy == false)
	{
		if (this->_dynamicMouse > 1 + *this->_pGlobalMultiplier * 0.75)
			this->_dynamicMouse -= 15 * *this->_pGlobalMultiplier * deltaTime;
		ddLine(this->_pPlayer->position.x, this->_pPlayer->position.y, mouseX, mouseY, WHITE);
		ddCircle(this->_mouseX, this->_mouseY, this->_dynamicMouse, WHITE);
	}
	else
	{
		if (this->_dynamicMouse < 15 * *this->_pGlobalMultiplier * 0.75)
			this->_dynamicMouse += 30 * *this->_pGlobalMultiplier * deltaTime;
		ddLine(this->_pPlayer->position.x, this->_pPlayer->position.y, this->_mouseX, this->_mouseY, GREEN);
		ddCircle(this->_mouseX, this->_mouseY, this->_dynamicMouse, GREEN);
	}
}

// calls all collision checks and handles them
const void GameScene::checkCol(float deltaTime)
{
	// checks if player is outside of screen, if true the player takes damage
	if (this->_pPlayer->position.x > SWIDTH || this->_pPlayer->position.x < 0 || this->_pPlayer->position.y > SHEIGHT || this->_pPlayer->position.y < 0)
		this->_pPlayer->takeDamage(deltaTime, 0.5);

	// checks if any of the enemies touch the player
	for (auto Enemy : this->_Enemies)
	{
		// if the col() function detects a run the player->takeDamage() function
		if (enemyColCheck(Enemy, this->_pPlayer))
			_pPlayer->takeDamage(deltaTime, Enemy->damageAmount * *this->_pGlobalMultiplier);

		// if the mouch touches an enemy turn _hitEnemy to true and add _Score per second
		if (mouseColCheck(Enemy, this->_mouseX, this->_mouseY))
		{
			addScore(deltaTime, Enemy->pointAmount / *this->_pGlobalMultiplier);
			this->_hitEnemy = true;
		}
	}
}

// checks if enemy collides with player
const bool GameScene::enemyColCheck(Enemy *enemy, Player *player)
{
	return (abs(enemy->position.x - *_pPlayerPosX) < (player->sprite()->size.x * player->scale.x + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - *_pPlayerPosY) < (player->sprite()->size.y * player->scale.y + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

// checks if enemy collides with mouse
const bool GameScene::mouseColCheck(Enemy *enemy, float _mouseX, float _mouseY)
{
	// check if the difference between the mouse and enemy position is less than a dynamic value
	return (abs(enemy->position.x - _mouseX) < (_dynamicMouse + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - _mouseY) < (_dynamicMouse + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

// creates all enteties needed on startup
const void GameScene::setupGame()
{
	this->_highScore = getScore();

	// creates player
	this->_pPlayer = new Player();
	this->addChild(_pPlayer);
	this->_pPlayerPosX = &_pPlayer->position.x;
	this->_pPlayerPosY = &_pPlayer->position.y;

	// creates ui
	this->_pUIelement = new UIElement(this->_pPlayer, &this->_Score, this->_highScore);
	this->addChild(this->_pUIelement);

	// creates starter enemy
	createLinePathEnemies(1);

	// _wroteFile = false
	this->_wroteFile = false;
}

// adds _Score based on parameters
const void GameScene::addScore(float deltaTime, unsigned int amount)
{
	// adds a variable _Score when player is alive and called
	if (this->_playerIsAlive)
	{
		this->_Score += amount * deltaTime / *this->_pGlobalMultiplier * 1.5;
		this->_displayedScore = (int)this->_Score;
	}
}

// spawns enemies based on a timer
const void GameScene::manageSpawns()
{
	if (this->_pTimer->seconds() >= this->_spawnRate)
	{
		// increases the spawnrate each _Time enemies spawn
		this->_spawnRate += 0.5;

		// starts the timer
		this->_pTimer->start();

		// creates enemies
		createAltPathEnemies(rand() % this->_altEnemyAmount);
		createStoicEnemies(1);
		createStraightEnemies((rand() % 2) + 1);
		this->_altEnemyAmount++;
	}
}

// starts timer
const void GameScene::timerSetup()
{
	// setups timer with 5 second spawn delay
	this->_spawnRate = 5;
	this->_pTimer->start();
}

// functions for creating enemies
const void GameScene::createAltPathEnemies(int amount)
{
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		this->_Enemies.push_back(new AltPathEnemy(&this->_enemyTarget));
	}
	for (const auto AltPathEnemy : this->_Enemies)
	{
		this->addChild(AltPathEnemy);
	}
}

const void GameScene::createLinePathEnemies(int amount)
{
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		_Enemies.push_back(new LinePathEnemy(&this->_enemyTarget));
	}
	for (const auto LineEnemy : this->_Enemies)
	{
		this->addChild(LineEnemy);
	}
}

const void GameScene::createStoicEnemies(int amount)
{
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		_Enemies.push_back(new StoicEnemy());
	}
	for (const auto StoicEnemy : this->_Enemies)
	{
		this->addChild(StoicEnemy);
	}
}

const void GameScene::createStraightEnemies(int amount)
{
	// adds a new enemy to the list before adding them as a child from the game
	for (size_t i = 0; i < amount; i++)
	{
		_Enemies.push_back(new StraightEnemy());
	}
	for (const auto StraightEnemy : this->_Enemies)
	{
		this->addChild(StraightEnemy);
	}
}

const void GameScene::saveScore(int _Score)
{
	if (!this->_playerIsAlive && !this->_wroteFile)
	{
		// if player is death save the _Score in highscore.txt if its higher than the int stored
		if (_Score > this->_highScore)
		{
			std::ofstream file_buffer("highscore.txt");
			file_buffer << _Score;
			file_buffer.close();
		}
		this->_wroteFile = true;
	}
}

const int GameScene::getScore()
{
	if (fileExists("highscore.txt"))
	{
		// returns the int stored in highscore.txt
		std::string _Score;
		std::ifstream file_buffer("highscore.txt");
		std::getline(file_buffer, _Score);
		file_buffer.close();
		return std::stoi(_Score);
	}
	else
	{
		// if highscore.txt doesn't exist creat it
		std::cout << "highscore.txt does not exist" << std::endl;
		std::ofstream file_buffer("highscore.txt");
		file_buffer << 0;
		file_buffer.close();
		return -1;
	}
}

const bool GameScene::fileExists(std::string fileName)
{
	// checks if file exitsts
	std::ifstream infile(fileName);
	return infile.good();
}