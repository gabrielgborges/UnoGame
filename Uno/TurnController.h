#pragma once
#include "Player.h"
#include "ICardEffectHandler.h"

class TurnController
{
public:
	TurnController() = default;

	void AddPlayer(shared_ptr<Player> newPlayer);

	void DefineRandomTurnOrder();

	void PlayTurns();

	inline void SkipTurn() { _skippableTurns++; };

	inline void SetTableCard(const Card tableCard) { _tableCard = tableCard; };

	inline void SetEffectHandler(weak_ptr<ICardEffectHandler> effectHandler){
		effectHandler.lock()->SetReverseTurnsCallback(std::bind(&TurnController::ReverseTurnOrder, this));
		effectHandler.lock()->SetSkipTurnCallback(std::bind(&TurnController::SkipTurn, this));
	};

	inline int NextPlayerToPlay() { return _nextPlayerToPlay; }

private:
	vector<shared_ptr<Player>> _currentPlayers;

	int _skippableTurns = 0;
	int _turnModifier = 1;
	int _nextPlayerToPlay = 0;

	Card _tableCard = Card(0, YELLOW, STANDARD);

	void ReverseTurnOrder();
};