#pragma once
#include "Card.h"
#include <map>
#include <unordered_map>

struct DeckConfiguration 
{
public:
	DeckConfiguration();
	~DeckConfiguration() = default;

	const std::unordered_map<Card, int, CardComparator, CardComparator> GetCardsAndDuplicates() {
		return _cardsAndDuplicates;
	}

private:
	std::unordered_map<Card, int, CardComparator, CardComparator> _cardsAndDuplicates;

	int _standardCardsCount = 9;
	int _standardCardsCopies = 2;
	int _specialCardsCopies = 2;
	int _extraCardsCopies = 4;
	int _plusTwoCardsToBuy = 2;

	void SetupCardSet(CardColor color);
	void SetupStandardCards(CardColor color);
	void SetupPlusCards(CardColor color, int copies, int amountToBuy);
	void SetupDiscardPlusCards(CardColor color, int copies, int amountToBuy);
	void SetupSpecialCards(CardColor color, int copies, CardType cardType);
};