#pragma once
#include <iostream>
#include <vector>

/*
* @brief Player football class
* @details Class is used to describe football player and his logic/
* and all stuff which is needed
*/
class Player
{
private:

public:
	explicit Player();
	Player(const Player&);
	explicit Player( Player&&);

	uint16_t tryTakeBall();
	const uint16_t& getChanceToGoal() { return _possibiltyToGoal; }
private:
	/*
	* @brief This struct includes coordinates of player
	*/

	uint16_t _speed;
	uint16_t _possibiltyToGoal;
	uint16_t _chanceWinBall;
};



