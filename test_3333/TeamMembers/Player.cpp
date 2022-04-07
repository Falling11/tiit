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
	this->_hasBall = false;
	this->_possibiltyToGoal = 1 + rand() % 99;
	this->_speed = 10 + rand() % 30;
	this->_chanceWinBall = 1 + rand() % 99;
}
Player::Player(const Player& obj)
{
	this->_chanceWinBall = obj._chanceWinBall;
	this->_hasBall = obj._hasBall;
	this->_possibiltyToGoal = obj._possibiltyToGoal;
	this->_speed = obj._speed;
}
Player::Player(Player&& obj)
{
	this->_chanceWinBall = std::move(obj._chanceWinBall);
	this->_hasBall = std::move(obj._hasBall);

	this->_possibiltyToGoal = std::move(obj._possibiltyToGoal);
	this->_speed = std::move(obj._speed);

}

uint16_t Player::tryTakeBall() { return ((this->_chanceWinBall * this->_possibiltyToGoal) / 100) * this->_speed; }
