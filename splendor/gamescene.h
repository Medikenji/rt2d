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
	unsigned int _altEnemyAmount = 50;
	float *_pGlobalMultiplier = &Splentity::sGameMultiplier;
	float _dynamicMouse = 1 + *_pGlobalMultiplier * 0.75;
	bool _wroteFile;
	long _highScore;

	// functions
	virtual void update(float deltaTime);
	const void updateFunctions();
	const void controlPlayer(float deltaTime);
	const void drawLine(float mx, float my, float deltaTime);
	const void checkCol(float deltaTime);
	const bool enemyColCheck(Enemy *enemy, Player *player);
	const bool mouseColCheck(Enemy *enemy, float mx, float my);
	const void setupGame();
	const void addScore(float deltaTime, const unsigned int amount);
	const void manageSpawns();
	const void timerSetup();
	const void createAltPathEnemies(int amount);
	const void createLinePathEnemies(int amount);
	const void createStoicEnemies(int amount);
	const void createStraightEnemies(int amount);
	const void saveScore(int score);
	const int getScore();
	const bool fileExists(std::string fileName);
};

#endif
