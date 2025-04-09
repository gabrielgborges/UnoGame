#pragma once
#include <vector>
#include <memory>
#include <iterator>
#include <algorithm>
#include <random>

#include "DeckConfiguration.h"

using namespace std;
class Deck
{
public:
	Deck();

	void Shuffle();

	void AddToDiscardPile(Card card);

	vector<Card> GetAvailableCards(int amount);

	vector<Card> GetDiscardedCards(int amount);

	inline Card const GetLastDiscardedCard() { return _discardPile.back(); };

private:
	DeckConfiguration _configuration;

	vector<Card> _availableCards; //why const Card fails
	vector<Card> _discardPile;

	int _cardsToRemainInPile = 1;

	default_random_engine _shuffleRNG{};

	void ReturnDiscardedCards();

	void SetupCards();

	void CreateCardCopies(const Card card, int copies);
};