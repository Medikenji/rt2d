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
	Timer _T;
	Vector2 _enemyTarget;
	float _mouseX;
	float _mouseY;
	float _Score;
	int _displayedScore;
	bool _hitEnemy;
	bool _playerIsAlive;
	float _spawnRate;
	int _altEnemyAmount = 100;
	float *_pGlobalMultiplier = &Splentity::sGameMultiplier;
	float _dynamicMouse = 1 + *_pGlobalMultiplier * 0.75;
	bool _wroteFile;
	long _highScore;

	// functions
	virtual void update(float deltaTime);
	void updateFunctions();
	void controlPlayer(float deltaTime);
	void drawLine(float mx, float my, float deltaTime);
	void checkCol(float deltaTime);
	bool enemyColCheck(Enemy *enemy, Player *player);
	bool mouseColCheck(Enemy *enemy, float mx, float my);
	void setupGame();
	void addScore(float deltaTime, int amount);
	void manageSpawns();
	void timerSetup();
	void createAltPathEnemies(int amount);
	void createLinePathEnemies(int amount);
	void createStoicEnemies(int amount);
	void createStraightEnemies(int amount);
	void saveScore(int score);
	int getScore();
	bool fileExists(std::string fileName);
};

#endif
