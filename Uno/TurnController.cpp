#include "TurnController.h"
#include <algorithm>
#include <random>
#include <iostream>

void TurnController::AddPlayer(shared_ptr<Player> newPlayer)
{
	_currentPlayers.push_back(newPlayer);
}

void TurnController::DefineRandomTurnOrder()
{
	default_random_engine shuffleRNG{};
	shuffle(_currentPlayers.begin(), _currentPlayers.end(), shuffleRNG);
	_nextPlayerToPlay = _currentPlayers.begin()->get()->GetIndex();
}

void TurnController::ReverseTurnOrder()
{
	_turnModifier *= -1;
}

void TurnController::PlayTurns()
{
	for (int currentTurn = (_turnModifier > 0) ? 0 : _currentPlayers.size() - 1; currentTurn < _currentPlayers.size() && currentTurn >= 0; currentTurn += _turnModifier) {
		int playersCount = _currentPlayers.size();
		if (currentTurn + _turnModifier >= playersCount) {
			_nextPlayerToPlay = _currentPlayers.begin()->get()->GetIndex();
		}
		else if (currentTurn + _turnModifier < 0) {
			_nextPlayerToPlay = _currentPlayers.back()->GetIndex();
		}
		else {
			_nextPlayerToPlay = _currentPlayers[currentTurn + _turnModifier]->GetIndex();
		}

		if (_skippableTurns > 0) {
			_skippableTurns--;
			continue;
		}
		_currentPlayers[currentTurn]->PlayTurn(_tableCard);
		std::cout << "\n\nPress anything to continue...";
		string anything;
		cin >> anything;
		std::cout << endl;
	};
}
