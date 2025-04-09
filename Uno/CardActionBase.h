#pragma once

class CardEffectHandler;

class CardActionBase
{
public:
	CardActionBase() = default;
	virtual ~CardActionBase();

	void virtual ApplyEffect(CardEffectHandler* effectsHandler);
};