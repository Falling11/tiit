#pragma once
#include "Team.h"

struct Ball
{
	uint16_t _xPos;
	uint16_t _yPos;
	bool _isFree;
};


class FootBallField
{

public:
	FootBallField();

	void startGame();
private:

	Team* _one;
	Team* _two;

	uint32_t _roundTime;

	Ball _ball;
};

