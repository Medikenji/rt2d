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

#define Up 100
#define Down 110
#define Left 120
#define Right 130
#define Boost 140

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();
	virtual void update(float deltaTime);
	void getMouse();
	void exitGame();
	void drawLine(float mx, float my);
	void controlPlayer(float deltaTime);
	void createAltPathEnemies(int amount);
	void createLinePathEnemies(int amount);
	void createStoicEnemies(int amount);
	void createStraightEnemies(int amount);
	void checkCol(float deltaTime);
	bool col(Enemy *enemy, Player *player);
	bool GameScene::mouseCol(Enemy *enemy, int mx, int my);
	void createSingleEntities();
	void AddScore(float deltaTime, int amount);
	void CreateScoreT();
	void ManageScoreT();

private:
	Player *player;
	UIElement *UIelement;
	std::vector<AltPathEnemy *> altPathEnemies;
	std::vector<LinePathEnemy *> linePathEnemies;
	std::vector<StoicEnemy *> stoicEnemies;
	std::vector<StraightEnemy *> straightEnemies;
	Timer t;
	Vector2 enemyTarget;
	float mx;
	float my;
	float score;
	int presentScore;
	bool HitEnemy;
	bool IsAlive;
	Text *text;
};

#endif
