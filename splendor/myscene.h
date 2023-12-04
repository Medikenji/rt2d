#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "player.h"
#include "enemy.h"
#include "altpathenemy.h"
#include "linepathenemy.h"

class MyScene : public Scene
{
public:
	MyScene();
	void getMouse();
	void exitGame();
	void drawLine(float mx, float my);
	void controlPlayer(float deltaTime);
	virtual ~MyScene();
	virtual void update(float deltaTime);

private:
	Player *player;
	AltPathEnemy *altEnemy;
	LinePathEnemy *straightEnemy;
	Enemy *enemy2;
	Timer t;
	float mx;
	float my;
};

#endif
