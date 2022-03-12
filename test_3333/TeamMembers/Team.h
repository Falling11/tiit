#pragma once
#include <vector>
#include <memory>
#include "Player.h"


class Team
{
public:

	Team();

private:

	std::vector<Player*> _team;

	bool _hasTeamBall;
};

