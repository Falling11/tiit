#include "Player.h"
#include <algorithm>

enum class Instance
{
	BALLTAKEN = 1,
	LOSTBALL = 0,
	GOAL = 2,
};


Player::Player()
{
	this->_xPos = 1 + rand() % 49;
	this->_yPos = 1 + rand() % 99;
	this->_hasBall = false;
	this->_hasTeamBall = false;
	this->_possibiltyToGoal = 1 + rand() % 99;
	this->_speed = 10 + rand() % 30;
	this->_chanceWinBall = 1 + rand() % 99;
}
Player::Player(const Player& obj)
{
	this->_chanceWinBall = obj._chanceWinBall;
	this->_hasBall = obj._hasBall;
	this->_hasTeamBall = obj._hasTeamBall;
	this->_possibiltyToGoal = obj._possibiltyToGoal;
	this->_speed = obj._speed;
}
Player::Player(Player&& obj)
{
	this->_chanceWinBall = std::move(obj._chanceWinBall);
	this->_hasBall = std::move(obj._hasBall);
	this->_hasTeamBall = std::move(obj._hasTeamBall);
	this->_possibiltyToGoal = std::move(obj._possibiltyToGoal);
	this->_speed = std::move(obj._speed);
	this->_xPos = std::move(obj._xPos);
	this->_yPos = std::move(obj._yPos);
}

uint16_t Player::tryTakeBall(const Player&obj)
{

	if (this->_chanceWinBall > obj._chanceWinBall)
		return static_cast<uint16_t>(Instance::BALLTAKEN);
	else
		return static_cast<uint16_t>(Instance::LOSTBALL);
}

uint16_t Player::moveToBall(const std::vector<Player*>& anotherTeam)
{
	Player* whichHasBall;
	for (size_t i{ 0 }; i < anotherTeam.size(); ++i)
	{
		if (anotherTeam[i]->_hasBall)
		{
			whichHasBall = anotherTeam[i];
			break;
		}
	}



	return 0;
}