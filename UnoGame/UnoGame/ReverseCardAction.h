#pragma once
#include "CardActionBase.h"

class ReverseCardAction : public CardActionBase
{
public:
	~ReverseCardAction();
	ReverseCardAction() = default;

	void ApplyEffect(CardEffectHandler* effectsHandler) override;
};

