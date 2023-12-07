// stoicenemy.cpp

#include "stoicenemy.h"

StoicEnemy::StoicEnemy()
		: Enemy()
{
	this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
}

StoicEnemy::~StoicEnemy()
{
}
