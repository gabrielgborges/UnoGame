#pragma once
#include "CardActionBase.h"

class PlusCardAction : public CardActionBase
{
public:
	PlusCardAction(int plusAmount) : _amount(plusAmount) { };
	~PlusCardAction();

	void ApplyEffect(CardEffectHandler* effectsHandler);
private:
	int _amount;
};