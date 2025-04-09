#include "Deck.h"
#include <iostream>

Deck::Deck()
{
	SetupCards();
}

void Deck::Shuffle()
{
	std::shuffle(_availableCards.begin(), _availableCards.end(), _shuffleRNG);
}

void Deck::AddToDiscardPile(Card card)
{
	_discardPile.push_back(card);
}

vector<Card> Deck::GetAvailableCards(int amount)
{
	vector<Card> returnedCards;
	for (int i = 0; i < amount && i < _availableCards.size(); i++) {
		returnedCards.push_back(_availableCards[i]);
	}
	_availableCards.erase(_availableCards.begin(), _availableCards.begin() + returnedCards.size());

	bool stillNeedCards = returnedCards.size() < amount;
	if (stillNeedCards) {
		ReturnDiscardedCards();
		int missingCards = amount - returnedCards.size();
		for (int i = 0; i < missingCards && i < _availableCards.size(); i++) {
			returnedCards.push_back(_availableCards[i]);
		}

		bool boughtEnoughCards = missingCards <= _availableCards.size();
		if (boughtEnoughCards) {
			_availableCards.erase(_availableCards.begin(), _availableCards.begin() + missingCards);
		}
		else {
			_availableCards.clear();
			cout << "There are no available cards enought to buy.";
		}
	}

	return returnedCards;
}

vector<Card> Deck::GetDiscardedCards(int amount)
{
	vector<Card> returnedCards;
	for (int i = 0; i < amount && i < _discardPile.size() - _cardsToRemainInPile; i++) {
		returnedCards.push_back(_discardPile[i]);
	}
	_discardPile.erase(_discardPile.begin(), _discardPile.begin() + returnedCards.size());

	bool stillNeedCards = returnedCards.size() < amount;
	if (stillNeedCards) {
		int missingCards = amount - returnedCards.size();

		vector<Card> cardsFromNormalPile = GetAvailableCards(missingCards);
		copy(cardsFromNormalPile.begin(), cardsFromNormalPile.end(), back_inserter(returnedCards));
	}

	return returnedCards;
}

void Deck::ReturnDiscardedCards()
{
	copy(_discardPile.begin(), _discardPile.end() - _cardsToRemainInPile, back_inserter(_availableCards));
	Shuffle();
	_discardPile.erase(_discardPile.begin(), _discardPile.end() - _cardsToRemainInPile);
}

void Deck::SetupCards()
{
	for (pair<Card, int> cardAndCopy : _configuration.GetCardsAndDuplicates()) {
		CreateCardCopies(cardAndCopy.first, cardAndCopy.second);
	}
	std::cout << "\nDeck cards: " << _availableCards.size() << endl;
	int i;
	cin >> i;
}

void Deck::CreateCardCopies(const Card card, int copies)
{
	for (int i = 0; i < copies; i++) {
		_availableCards.push_back(card);
	}
}
