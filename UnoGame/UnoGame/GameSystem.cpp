#include "GameSystem.h"
#include "AiInputComponent.h"
#include "KeyboardInputComponent.h"

void GameSystem::SetupGame()
{
	DecidePlayersCount();
	CreatePlayers();
	_cardTable->Setup();
}

void GameSystem::StartGame()
{
	_cardTable->StartGame();
}

void GameSystem::DecidePlayersCount()
{
	cout << "Welcome to the new and old UNO game!!!\n";
	bool playerNumbersIsInvalid = _currentPlayersCount > _maxPlayers || _currentPlayersCount < _minPlayers;
	
	while (playerNumbersIsInvalid) {
		cout << "Please, choose the amount of players in the table: " << "(less than " << (_maxPlayers + 1) << " but greater than " << (_minPlayers - 1) << ")\n";
		cin >> _currentPlayersCount;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		playerNumbersIsInvalid = _currentPlayersCount > _maxPlayers || _currentPlayersCount < _minPlayers;
	}
}

void GameSystem::CreatePlayers()
{
	CreateMainPlayer();
	for (int i = 1; i < _currentPlayersCount; i++) {
		_cardTable->AddPlayer(make_shared<Player>(_cardTable->PlayersCount() + 1, make_shared<AiInputComponent>()));
	}
}

void GameSystem::CreateMainPlayer()
{
	_cardTable->AddPlayer(make_shared<Player>(_cardTable->PlayersCount() + 1, make_shared<KeyboardInputComponent>()));
}
