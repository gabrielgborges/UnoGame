#include "Player.h"
#include <iterator>
#include <iostream>

void Player::PlayTurn(Card tableCard)
{
	_inputComponent->ChooseInput(_handCards, tableCard);
}

void Player::BuyCard()
{
	_buyCardCallback(_index);
}

void Player::BuyCard(Card card)
{
	cout << "Player " << _index << " drew one card.";
	_handCards.emplace_back(card);
}

void Player::BuyCard(vector<Card> cards)
{
	copy(cards.begin(), cards.end(), back_inserter(_handCards));
	ShowCurrentCards();
}

void Player::YellUno()
{
	_yellUno(_index);
	_inputComponent->HasExtraMovement = true;
}

void Player::PlayCard(Card card)
{
	cout << "\nPlayer " << _index << " played " << card.CardDisplay() << endl;

	_handCards.erase(remove(_handCards.begin(), _handCards.end(), card));
	_playCardCallback(card, _index);
}

void Player::ShowCurrentCards()
{
	std::cout << "\nPlayer " << _index << " cards are : \n";

	for (Card card : _handCards) {
		std::cout << card.CardDisplay() << ", ";
	}
}
