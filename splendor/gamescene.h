#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "player.h"
#include "enemy.h"
#include "altpathenemy.h"
#include "linepathenemy.h"
#include "uielement.h"
#include "splentity.h"

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
	void checkCol(float deltaTime);
	bool col(Enemy *enemy);
	void createSingleEntities();

private:
	Player *player;
	UIElement *UIelement;
	std::vector<AltPathEnemy *> altPathEnemies;
	std::vector<LinePathEnemy *> linePathEnemies;
	Timer t;
	Vector2 enemyTarget;
	float mx;
	float my;
};

#endif
