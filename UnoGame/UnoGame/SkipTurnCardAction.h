#pragma 
#include "CardActionBase.h"

class SkipTurnCardAction : public CardActionBase
{
public:
	SkipTurnCardAction() = default;
	~SkipTurnCardAction();

	void ApplyEffect(CardEffectHandler* effectsHandler) override;
};