#include "gamescene.h"

GameScene::GameScene() : Scene()
{

	score = 0;
	// starts timer on setup
	t.start();

	// creates and starts timer
	timer = new Timer();
	TimerSetup();

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
	drawLine(mx, my, deltaTime);
	ManageScoreT();
	ManageSpawns();
	saveScore(score);
}

// small things that need to be called every frame
void GameScene::updateFunctions()
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
}

// calls player controls through inputs
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

// draws line from player through mouse depending on scenario
void GameScene::drawLine(float mx, float my, float deltaTime)
{
	// clears the line before another one gets drawn
	ddClear();

	// draws line after checking if an enemy has been hit for the right color
	if (HitEnemy == false)
	{
		if (mouseAnimManager > 1 + *globalMultiplier * 0.75)
		{
			mouseAnimManager -= 15 * *globalMultiplier * deltaTime;
		}
		ddLine(player->position.x, player->position.y, mx, my, WHITE);
		ddCircle(mx, my, mouseAnimManager, WHITE);
	}
	else
	{
		if (mouseAnimManager < 15 * *globalMultiplier * 0.75)
		{
			mouseAnimManager += 30 * *globalMultiplier * deltaTime;
		}
		ddLine(player->position.x, player->position.y, mx, my, GREEN);
		ddCircle(mx, my, mouseAnimManager, GREEN);
	}
}

// calls all collision checks and handles them
void GameScene::checkCol(float deltaTime)
{
	// checks if player is outside of screen, if true the player takes damage
	if (player->position.x > SWIDTH || player->position.x < 0 || player->position.y > SHEIGHT || player->position.y < 0)
	{
		player->takeDamage(deltaTime, 0.5);
	}

	// checks if any of the enemies touch the player
	for (auto Enemy : _enemies)
	{
		// if the col() function detects a run the player->takeDamage() function
		if (enemyColCheck(Enemy, player))
		{
			player->takeDamage(deltaTime, Enemy->damageAmount * *globalMultiplier);
		}

		// if the mouch touches an enemy turn HitEnemy to true and add score per second
		if (mouseColCheck(Enemy, mx, my))
		{
			AddScore(deltaTime, Enemy->pointAmount / *globalMultiplier);
			HitEnemy = true;
		}
	}
}

// checks if enemy collides with player
bool GameScene::enemyColCheck(Enemy *enemy, Player *player)
{
	// check if the difference between the player and enemy position is less than a dynamic value
	return (abs(enemy->position.x - player->position.x) < (player->sprite()->size.x * player->scale.x + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - player->position.y) < (player->sprite()->size.y * player->scale.y + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

// checks if enemy collides with mouse
bool GameScene::mouseColCheck(Enemy *enemy, float mx, float my)
{
	// check if the difference between the mouse and enemy position is less than a dynamic value
	return (abs(enemy->position.x - mx) < (mouseAnimManager + (enemy->sprite()->size.x * enemy->scale.x) / 2)) && (abs(enemy->position.y - my) < (mouseAnimManager + (enemy->sprite()->size.y * enemy->scale.y) / 2));
}

// creates all enteties needed on startup
void GameScene::setupGame()
{
	// creates player
	player = new Player();
	this->addChild(player);

	// creates ui
	UIelement = new UIElement(player, &score);
	this->addChild(UIelement);
	CreateScoreT();

	// creates starter enemy
	createLinePathEnemies(1);

	// _WroteFile = false
	_WroteFile = false;

	HighScore = getScore();
}

// adds score based on parameters
void GameScene::AddScore(float deltaTime, int amount)
{
	// adds a variable score when player is alive and called
	if (IsAlive)
	{
		score += amount * deltaTime / *globalMultiplier * 1.5;
		currentScore = (int)score;
	}
}

// creates score text
void GameScene::CreateScoreT()
{
	// sets score to 0
	score = 0;
	currentScore = 0;

	// creates score text
	this->text = new Text();
	this->text->position = Vector2(20, SHEIGHT - 20);
	this->addChild(this->text);
	this->text->scale = Vector2(0.75, 0.75);
}

// updates the score text
void GameScene::ManageScoreT()
{
	// updates te score text
	if (IsAlive)
	{
		this->text->message(std::to_string(currentScore));
	}
	else
	{
		this->text->position = Vector2(SWIDTH / 10, SHEIGHT / 2);
		this->text->scale = Vector2(1, 1);
		this->text->message("Game Over, your score is:	" + std::to_string(currentScore), RED);
	}
}

// spawns enemies based on a timer
void GameScene::ManageSpawns()
{
	if (timer->seconds() >= spawnRate)
	{
		// increases the spawnrate each time enemies spawn
		spawnRate += 0.5;

		// starts the timer
		timer->start();

		// creates enemies
		createAltPathEnemies(rand() % enemyAmount);
		createStoicEnemies(1);
		createStraightEnemies((rand() % 2) + 1);
		enemyAmount++;
	}
}

// starts timer
void GameScene::TimerSetup()
{
	// setups timer with 5 second spawn delay
	spawnRate = 5;
	timer->start();
}

// functions for creating enemies
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

void GameScene::saveScore(int score)
{
	if (!IsAlive && !_WroteFile)
	{
		// if player is death save the score in highscore.txt if its higher than the int stored
		if (score > HighScore)
		{
			std::ofstream file_buffer("highscore.txt");
			file_buffer << score;
			file_buffer.close();
		}
		_WroteFile = true;
	}
}

int GameScene::getScore()
{
	if (fileExists("highscore.txt"))
	{
		// returns the int stored in highscore.txt
		std::string score;
		std::ifstream file_buffer("highscore.txt");
		std::getline(file_buffer, score);
		file_buffer.close();
		return std::stoi(score);
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

bool GameScene::fileExists(std::string filename)
{
	// checks if file exitsts
	std::ifstream infile(filename);
	return infile.good();
}