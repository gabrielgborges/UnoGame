#include "AiInputComponent.h"

AiInputComponent::AiInputComponent()
{
}

void AiInputComponent::ChooseInput(std::vector<Card> handCards, Card tableCard)
{
	std::vector<std::function<void()>> possibleInputs;

	for (int i = 0; i < handCards.size(); i++) {
		if (tableCard.IsPlayableWith(handCards[i])) {
			possibleInputs.push_back([=]() {_playCardInput(handCards[i]); });
		}
	}

	bool hasCardsToPlay = possibleInputs.size() > 0;

	if (!hasCardsToPlay) {
		_buyCardInput();
		return;
	}

	possibleInputs.push_back(_yellUnoInput);
	
	std::uniform_int_distribution<int> distribution(0, possibleInputs.size() - 1);
	int choosenInput = distribution(generator);
	possibleInputs[choosenInput]();
	if (HasExtraMovement) {
		possibleInputs.erase(possibleInputs.begin() + choosenInput);
		TakeExtraInputs(handCards, tableCard, possibleInputs);
	}
}

void AiInputComponent::TakeExtraInputs(std::vector<Card> handCards, Card tableCard, std::vector<std::function<void()>> possibleInputs)
{
	int inputsCount = 0;
	for (int i = 0; i < handCards.size(); i++) {
		if (tableCard.IsPlayableWith(handCards[i])) {
			inputsCount++;
		}
	}

	HasExtraMovement = false;

	std::uniform_int_distribution<int> distribution(0, possibleInputs.size() - 1);
	int choosenInput = distribution(generator);
	possibleInputs[choosenInput]();
}
