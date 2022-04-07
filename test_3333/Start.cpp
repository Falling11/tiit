#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <thread>

#include "TeamMembers/Team.h"

using namespace std;

enum MagicConst
{
	AMOUNTGAMES = 1000,
};

struct Score
{
	uint16_t first;
	uint16_t second;
};

Score football;

enum class StatusBall
{
	WITHPLAYER,
	NONE,
};

StatusBall ball(StatusBall::NONE);

std::mutex globalMu;

Team one("SPARTAK"), two("UGANDA");

void temporary(Team& team, uint16_t&, uint16_t&);


int main()
{
	srand(time(NULL) * 1000);
	setlocale(0, "");

	cout << "Do you wanna play a game?\n";
	
	uint16_t firstTeam{ 0 }, secondTeam{ 0 };
	thread
		teamOne(temporary, std::ref(one), std::ref(firstTeam), std::ref(secondTeam)),
		teamTwo(temporary, std::ref(two), std::ref(secondTeam), std::ref(firstTeam));

	teamOne.join();
	teamTwo.join();

	cout << "\nScore is: " + std::to_string(one.getScore()) + ':' + std::to_string(two.getScore());
	return 0;
}

void temporary(Team& team, uint16_t& own, uint16_t& enemy)
{
	 uint16_t counter{ 0 };
	while (counter<AMOUNTGAMES)
	{
		Player ourFoot = *team._team[1 + rand() % 10];
		own = ourFoot.tryTakeBall();
		std::this_thread::sleep_for(1ms);


		//lock_guard<mutex> lock(globalMu);
		globalMu.lock();
		if(ball==StatusBall::NONE)
		if (own > enemy)
		{
			ball = StatusBall::WITHPLAYER;
			cout << this_thread::get_id() << "<-- Team " + std::string(team.getName()) + " won!      ";
			cout << "Chance " + std::string(team.getName()) + " is " + std::to_string(own) + " vs " + std::to_string(enemy) << endl;
			++team;		
			std::this_thread::sleep_for(5ms);
		}
		else if (own < enemy)
		{
			cout << this_thread::get_id() << "<-- Team " + std::string(team.getName()) + " lost!\n";
		}
		else
		{
			cout << this_thread::get_id() << "<--TIER!\n";
		}
		//globalMu.unlock();
		
		++counter;
		//obalMu.lock();
		if (ball != StatusBall::NONE)
		{
			ball = StatusBall::NONE;
			enemy;
			own;
		}
		globalMu.unlock();
		
	}
}