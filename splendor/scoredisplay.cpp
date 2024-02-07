// scoredisplay.cpp

#include "scoredisplay.h"

ScoreDisplay::ScoreDisplay(Player *_pPlayer, float *_Score, long _Highscore) : Entity()
{
	this->_Highscore = _Highscore;
	this->_pPlayer = _pPlayer;
	createScoreT();
	_pScore = _Score;
	std::cout << _Score << std::endl;
}

ScoreDisplay::~ScoreDisplay()
{
}

void ScoreDisplay::update(float deltaTime)
{
	manageScoreT();
}

// creates _Score text
void ScoreDisplay::createScoreT()
{
	_displayedScore = 0;

	// creates _Score text
	this->_pText = new Text();
	this->_pText->position = Vector2(20, SHEIGHT - 20);
	this->addChild(this->_pText);
	this->_pText->scale = Vector2(0.75, 0.75);
}

// updates the _Score text
void ScoreDisplay::manageScoreT()
{
	// updates te _Score text
	if (_pPlayer->getLivingStatus())
	{
		_displayedScore = (int)*_pScore;
		this->_pText->message(std::to_string(_displayedScore), dynamicColor(255, 255, 0));
	}
	else
	{
		this->_pText->position = Vector2(SWIDTH / 10, SHEIGHT / 2);
		this->_pText->scale = Vector2(1, 1);
		this->_pText->message("Game Over, your _Score is:	" + std::to_string(_displayedScore), RED);
	}
}

RGBAColor ScoreDisplay::dynamicColor(int r, int g, int b)
{
	if (*_pScore > _Highscore)
	{
		return RGBAColor(r, g, b, 255);
	}
	else
	{
		return RGBAColor(255, 255, 255);
	}
}