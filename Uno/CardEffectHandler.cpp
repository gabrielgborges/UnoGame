#include "CardEffectHandler.h"
#include "ReverseCardAction.h"
#include "SkipTurnCardAction.h"
#include "PlusCardAction.h"
#include "DiscardedPlusCardAction.h"

CardEffectHandler::CardEffectHandler()
{
	for (CardType effect : _availableEffects) {
		switch (effect) {
		case STANDARD:
			//_cardEffectByType.emplace(effect, make_unique<CardActionBase>());
			break;
		case REVERSE:
			_cardEffectByType.emplace(effect, make_unique<ReverseCardAction>());
			break; 
		case SKIP:
			_cardEffectByType.emplace(effect, make_unique<SkipTurnCardAction>());
			break; 
		case PLUS_TWO:
			_cardEffectByType.emplace(effect, make_unique<PlusCardAction>(2));
			break;
		case DISCARD_PLUS_TWO:
			_cardEffectByType.emplace(effect, make_unique<DiscardedPlusCardAction>(2));
			break;
		}
	}
}

void CardEffectHandler::Resolve(CardType card)
{
	if (_cardEffectByType.find(card) != _cardEffectByType.end()) {
		_cardEffectByType[card]->ApplyEffect(this);
	}
}

void CardEffectHandler::ReverseTurns()
{
	_reverseTurnCallback();
}

void CardEffectHandler::SkipTurn()
{
	_skipTurnCallback();
}

void CardEffectHandler::BuyCards(int amount)
{
	_buyCardsCallback(amount);
}

void CardEffectHandler::BuyDiscardedCards(int amount)
{
	_buyDiscardedCardsCallback(amount);
}
