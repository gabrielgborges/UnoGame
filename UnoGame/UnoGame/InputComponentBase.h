#pragma once
#include <vector>
#include <functional>
#include "Card.h"

class InputComponentBase
{
public:
	bool HasExtraMovement = false;

	void virtual ChooseInput(const std::vector<Card> handCards, const Card tableCard);
	virtual ~InputComponentBase();

	inline void SetBuyCardInput(const std::function<void()> callback) { _buyCardInput = callback; };

	inline void SetYellUnoInput(const std::function<void()> callback) { _yellUnoInput = callback; };

	inline void SetPlayCardInput(const std::function<void(Card card)> callback) { _playCardInput = callback; };

protected:
	std::function<void()> _buyCardInput;
	std::function<void()> _yellUnoInput;
	std::function<void(Card card)> _playCardInput;

	InputComponentBase() = default;

	void virtual TakeExtraInputs(std::vector<Card> handCards, Card tableCard, std::vector<std::function<void()>> possibleInputs);


};

