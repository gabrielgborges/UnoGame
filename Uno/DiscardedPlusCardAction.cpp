#include "DiscardedPlusCardAction.h"
#include "CardEffectHandler.h"

DiscardedPlusCardAction::~DiscardedPlusCardAction()
{
}

void DiscardedPlusCardAction::ApplyEffect(CardEffectHandler* effectsHandler)
{
	effectsHandler->BuyDiscardedCards(_amount);
}
