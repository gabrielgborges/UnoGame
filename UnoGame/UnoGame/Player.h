#pragma once
#include <vector>
#include <memory>
#include "Card.h"
#include "InputComponentBase.h"

using namespace std;

class Player
{
public:
	Player() = default;

	Player(int index, shared_ptr<InputComponentBase> input) : _index(index), _inputComponent(input) {
		_inputComponent->SetYellUnoInput(std::bind(&Player::YellUno, this));
		_inputComponent->SetPlayCardInput(std::bind(&Player::PlayCard, this, placeholders::_1));
		_inputComponent->SetBuyCardInput(std::bind(static_cast<void(Player::*)()>(&Player::BuyCard), this));
	};

	void PlayTurn(Card tableCard);

	void BuyCard();

	void BuyCard(Card card);

	void BuyCard(vector<Card> card);

	inline void SetBuyCardCallback(const std::function<void(int playerIndex)> callback) { _buyCardCallback = callback; };

	inline void SetPlayCardCallback(const std::function<void(Card card, int playerIndex)> callback) { _playCardCallback = callback; };

	inline void SetYellUnoCallback(const std::function<void(int playerIndex)> callback) { _yellUno = callback; };

	inline int const GetIndex() { return _index; };

	inline int const CardCount() { return _handCards.size(); };

private:
	int const _index;

	shared_ptr<InputComponentBase> _inputComponent;

	vector<Card> _handCards;

	std::function<void(Card card, int playerIndex)> _playCardCallback;
	std::function<void(int playerIndex)> _yellUno;
	std::function<void(int playerIndex)> _buyCardCallback;

	void YellUno();

	void PlayCard(Card card);



	void ShowCurrentCards();
};