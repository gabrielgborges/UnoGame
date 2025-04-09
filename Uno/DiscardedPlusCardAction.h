#pragma once
#include "CardActionBase.h"

class DiscardedPlusCardAction : public CardActionBase
{
public:
	DiscardedPlusCardAction(int plusAmount) : _amount(plusAmount) { };
	~DiscardedPlusCardAction();

	void ApplyEffect(CardEffectHandler* effectsHandler) override;
private:
	int _amount;
};