#include "PlusCardAction.h"
#include "CardEffectHandler.h"

PlusCardAction::~PlusCardAction()
{
}

void PlusCardAction::ApplyEffect(CardEffectHandler* effectsHandler)
{
	effectsHandler->BuyCards(_amount);
}
