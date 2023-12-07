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

private:
	Player *player;
	AltPathEnemy *altEnemy;
	LinePathEnemy *straightEnemy;
	Timer t;
	Vector2 enemyTarget;
	float mx;
	float my;
};

#endif
