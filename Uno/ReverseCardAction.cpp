#include "ReverseCardAction.h"
#include "CardEffectHandler.h"

void ReverseCardAction::ApplyEffect(CardEffectHandler* effectsHandler)
{
	effectsHandler->ReverseTurns();
}

ReverseCardAction::~ReverseCardAction()
{
}
