#pragma once
#include <unordered_map>
#include <memory>
#include <vector>
#include "CardType.h"
#include "CardActionBase.h"
#include "ICardEffectHandler.h"

class CardEffectHandler : public ICardEffectHandler
{
public:
	CardEffectHandler();

	void Resolve(CardType card);

	void ReverseTurns();

	void SkipTurn();
	
	void BuyCards(int amount);

	void BuyDiscardedCards(int amount);

private:
	unordered_map<CardType, unique_ptr<CardActionBase>> _cardEffectByType;
	vector<CardType> _availableEffects{ STANDARD, REVERSE, SKIP, PLUS_TWO, DISCARD_PLUS_TWO};
};

