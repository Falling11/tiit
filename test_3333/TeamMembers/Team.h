#pragma once
#include <vector>
#include <memory>
#include <mutex>

#include "Player.h"

enum class StatusBall;

class Team
{
public:

	Team(std::string_view);

	const std::string_view& getName() { return name; }
	const uint16_t& getScore() { return score; };

	void operator++() { ++this->score; }

	std::vector<Player*> _team;
private:

	bool _hasTeamBall;
	uint16_t score;
	std::string_view name;
	
};

