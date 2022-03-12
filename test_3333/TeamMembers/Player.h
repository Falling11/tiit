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

	uint16_t tryTakeBall(const Player&);
	uint16_t tryToGoal();
	uint16_t moveToBall(const std::vector<Player*>&anotherTeam);
private:
	/*
	* @brief This struct includes coordinates of player
	*/

	uint16_t _xPos;
	uint16_t _yPos;
	
	bool _hasBall;
	bool _hasTeamBall;

	uint16_t _speed;
	uint16_t _possibiltyToGoal;
	uint16_t _chanceWinBall;
};



