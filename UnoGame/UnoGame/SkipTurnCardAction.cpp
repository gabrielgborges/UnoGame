#include "SkipTurnCardAction.h"
#include "CardEffectHandler.h"

void SkipTurnCardAction::ApplyEffect(CardEffectHandler* effectsHandler)
{
	effectsHandler->SkipTurn();
}

SkipTurnCardAction::~SkipTurnCardAction()
{
}
