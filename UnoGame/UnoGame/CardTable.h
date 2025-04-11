#pragma once
#include "TurnController.h"
#include "Deck.h"
#include <iostream>
#include "CardEffectHandler.h"

class CardTable
{
public:
	CardTable() = default;
	~CardTable() = default;
	
	void AddPlayer(shared_ptr<Player> newPlayer);

	void Setup();

	void StartGame();

	void GiveInitialHands();

	inline int PlayersCount() { return _playersInTable.size(); };
private:
	vector<shared_ptr<Player>> _playersInTable;
	vector<shared_ptr<Player>> _playersInUNO;

	unique_ptr<Deck> _deck = make_unique<Deck>();
	unique_ptr<TurnController> _turnController = make_unique<TurnController>();
	shared_ptr<CardEffectHandler> _effectHandler = make_shared<CardEffectHandler>();

	bool _gameIsFinished = false;

	int const _standardCardDraw = 1;
	int const _initialHands = 7;
	int const _wrongUnoPenalty = 2;

	void DefineRandomPlayOrder();

	void HandleCardBuy(int player);

	void HandleForcedCardBuy(int amount);

	void HandleForcedDiscardedCardBuy(int amount);

	void HandleCardDiscard(Card card);

	void HandleCardDiscard(Card card, int playerIndex);

	void HandleUnoYell(int playerIndex);

	void ApplyUnoPenalties(int playerIndex);

	void CheckPlayerWon(int playerIndex);
};

