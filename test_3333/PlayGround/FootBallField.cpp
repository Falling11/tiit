#include "FootBallField.h"

FootBallField::FootBallField()
{
	this->_one = new Team();
	this->_two = new Team();

	this->_ball._xPos = 1 + rand() % 49;
	this->_ball._yPos = 1 + rand() % 99;
	this->_ball._isFree = false;
	this->_roundTime = 0;
}