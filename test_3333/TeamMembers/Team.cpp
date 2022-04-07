#include "Team.h"


Team::Team(std::string_view name)
{
	this->_team.resize(11);
	for (size_t i{ 0 }; i < this->_team.size(); ++i)
	{
		this->_team[i] = new Player();
	}
	this->_hasTeamBall = false;
	this->name = name;
}