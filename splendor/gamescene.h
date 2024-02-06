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
	GameScene();
	virtual ~GameScene();

private:
	// variables
	Timer *timer;
	Player *player;
	UIElement *UIelement;
	std::vector<Enemy *> _enemies;
	Timer t;
	Vector2 enemyTarget;
	float mx;
	float my;
	float score;
	int currentScore;
	bool HitEnemy;
	bool IsAlive;
	Text *text;
	float spawnRate;
	int enemyAmount = 100;
	float *globalMultiplier = &Splentity::speedMultiplier;
	float mouseAnimManager = 1 + *globalMultiplier * 0.75;
	bool _WroteFile;
	long HighScore;

	// functions
	virtual void update(float deltaTime);
	void updateFunctions();
	void controlPlayer(float deltaTime);
	void drawLine(float mx, float my, float deltaTime);
	void checkCol(float deltaTime);
	bool enemyColCheck(Enemy *enemy, Player *player);
	bool mouseColCheck(Enemy *enemy, float mx, float my);
	void setupGame();
	void AddScore(float deltaTime, int amount);
	void CreateScoreT();
	void ManageScoreT();
	void ManageSpawns();
	void TimerSetup();
	void createAltPathEnemies(int amount);
	void createLinePathEnemies(int amount);
	void createStoicEnemies(int amount);
	void createStraightEnemies(int amount);
	void saveScore(int score);
	int getScore();
	bool fileExists(std::string filename);
};

#endif
