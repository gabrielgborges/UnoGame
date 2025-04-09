#include "DeckConfiguration.h"

DeckConfiguration::DeckConfiguration()
{
	SetupCardSet(RED);
	SetupCardSet(BLUE);
	SetupCardSet(YELLOW);
	SetupCardSet(GREEN);
}

void DeckConfiguration::SetupCardSet(CardColor color)
{
	SetupStandardCards(color);
	SetupSpecialCards(color, _specialCardsCopies, SKIP);
	SetupSpecialCards(color, _specialCardsCopies, REVERSE);
	SetupPlusCards(color, _specialCardsCopies, _plusTwoCardsToBuy);
	SetupDiscardPlusCards(color, _extraCardsCopies, _plusTwoCardsToBuy);
}

void DeckConfiguration::SetupStandardCards(CardColor color)
{
	for (int i = 0; i < _standardCardsCount + 1; i++) {
		Card createdCard(i, color, STANDARD);
		_cardsAndDuplicates.emplace( createdCard, _standardCardsCopies);
	}
}

void DeckConfiguration::SetupPlusCards(CardColor color, int copies, int amountToBuy)
{
	Card createdCard(amountToBuy, color, PLUS_TWO);
	_cardsAndDuplicates.insert({ createdCard, copies });
}

void DeckConfiguration::SetupDiscardPlusCards(CardColor color, int copies, int amountToBuy)
{
	Card createdCard(amountToBuy, color, DISCARD_PLUS_TWO);
	_cardsAndDuplicates.insert({ createdCard, copies });
}

void DeckConfiguration::SetupSpecialCards(CardColor color, int copies, CardType cardType)
{
	Card createdCard(0, color, cardType);
	_cardsAndDuplicates.insert({ createdCard, copies });
}
