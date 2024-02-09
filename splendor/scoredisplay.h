// scoredisplay.h

#ifndef SCOREDISPLAY_H
#define SCOREDISPLAY_H

#include <entity.h>
#include <text.h>
#include "player.h"

class ScoreDisplay : public Entity
{
public:
	ScoreDisplay(Player *_pPlayer, float *_Score, long _Highscore);
	virtual ~ScoreDisplay();

private:
	// variables
	float *_pScore;
	long _Highscore;
	Text *_pText;
	Player *_pPlayer;
	// functions
	virtual void update(float deltaTime);
	void manageScoreT();
	void createScoreT();
	RGBAColor dynamicColor(int r, int g, int b);
};

#endif /* SCOREDISPLAY_H */
