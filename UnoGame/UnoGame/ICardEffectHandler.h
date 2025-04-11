#pragma once
#include <functional>

using namespace std;
class ICardEffectHandler
{
public:
	inline void SetReverseTurnsCallback(function<void()> callback) { _reverseTurnCallback = callback; };

	inline void SetSkipTurnCallback(function<void()> callback) { _skipTurnCallback = callback; };

	inline void SetBuyCardsCallback(function<void(int amount)> callback) { _buyCardsCallback = callback; };

	inline void SetBuyDiscardedCardsCallback(function<void(int amount)> callback) { _buyDiscardedCardsCallback = callback; };

protected:
	function<void()> _reverseTurnCallback;

	function<void()> _skipTurnCallback;

	function<void(int amount)> _buyCardsCallback;

	function<void(int amount)> _buyDiscardedCardsCallback;
};

