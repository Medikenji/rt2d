#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "player.h"
#include "enemy.h"
#include "altpathenemy.h"
#include "linepathenemy.h"

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

private:
	Player *player;
	std::vector<AltPathEnemy *> altPathEnemies;
	std::vector<LinePathEnemy *> linePathEnemies;

	Timer t;
	Vector2 enemyTarget;
	float mx;
	float my;
};

#endif
