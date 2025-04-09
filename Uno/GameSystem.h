#pragma once
#include "CardTable.h"

using namespace std;

class GameSystem
{
public:
	GameSystem() = default;

	void SetupGame();

	void StartGame();

private:
	unique_ptr<CardTable> _cardTable = make_unique<CardTable>();
	
	int _maxPlayers = 10;
	int _minPlayers = 2;
	int _currentPlayersCount = 0;

	void DecidePlayersCount();

	void CreatePlayers();

	void CreateMainPlayer();
};

