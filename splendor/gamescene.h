#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "player.h"
#include "enemy.h"
#include "altpathenemy.h"
#include "linepathenemy.h"
#include "uielement.h"
#include "stoicenemy.h"
#include "splentity.h"
#include "straightenemy.h"
#include "timer.h"
#include <fstream>
#include <sstream>
#include <color.h>
#include <math.h>
#include <algorithm>

#define UP 100
#define DOWN 110
#define LEFT 120
#define RIGHT 130
#define BOOST 140

class GameScene : public Scene
{
public:
	// functions
	GameScene();
	virtual ~GameScene();

private:
	// variables
	Timer *_pTimer;
	Player *_pPlayer;
	UIElement *_pUIelement;
	std::vector<Enemy *> _Enemies;
	float *_pPlayerPosX;
	float *_pPlayerPosY;
	Timer _T;
	Vector2 _enemyTarget;
	float _mouseX;
	float _mouseY;
	float _Score;
	int _displayedScore;
	bool _hitEnemy;
	bool _playerIsAlive;
	float _spawnRate;
	unsigned int _altEnemyAmount;
	float *_pGlobalMultiplier = &Splentity::sGameMultiplier;
	/// @brief Dynamically decides the mouse size depending on in game factors
	float _dynamicMouse = 1 + *_pGlobalMultiplier * 0.75;
	bool _wroteFile;
	long _highScore;

	// functions
	virtual void update(float deltaTime);
	/// @brief Small variable changes that need to be updated every frame
	/// @return
	const void updateFunctions();
	/// @brief Passes the input to the player
	/// @return
	const void controlPlayer(float deltaTime);
	/// @brief Draws and manages the mouse cursor and the line thats drawn to it
	/// @return
	const void drawLine(float deltaTime);
	/// @brief A wrapper function that calls all collision checks
	/// @return
	const void checkCol(float deltaTime);
	/// @brief Checks if this enemy in in the collision radius with the player
	/// @return
	const bool enemyColCheck(Enemy *enemy, Player *player);
	/// @brief Checks if enemy is in the collision radius of the dynamic cursor
	/// @param mx Mouse X position
	/// @param my Mouse Y position
	/// @return
	const bool mouseColCheck(Enemy *enemy);
	/// @brief Calls all functions that need to be called on startup once
	/// @return
	const void setupGame();
	/// @brief Adds a certain amount of score when called
	/// @param deltaTime
	/// @param amount
	/// @return
	const void addScore(float deltaTime, const unsigned int amount);
	/// @brief Spawns in a new wave every time the timer reaches 0, then it resets the timer
	/// @return
	const void manageSpawns();
	const void timerSetup();
	const void createAltPathEnemies(int amount);
	const void createLinePathEnemies(int amount);
	const void createStoicEnemies(int amount);
	const void createStraightEnemies(int amount);
	/// @brief Saves the score amount (if higher than the highscore) once the player dies
	/// @param score The amount that needs to be saved
	/// @return
	const void saveScore(int score);
	const int getScore();
	const bool fileExists(std::string fileName);
};

#endif
