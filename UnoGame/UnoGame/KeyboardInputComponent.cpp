#include "KeyboardInputComponent.h"
#include <iostream>

KeyboardInputComponent::KeyboardInputComponent()
{
}

void KeyboardInputComponent::ChooseInput(std::vector<Card> handCards, Card tableCard)
{
	cout << "\nYour hand cards are:\n";

	for (Card card : handCards) {
		cout << card.CardDisplay() << ", ";
	}

	cout << "\nSelect your action by tipping the number besides it:";

	std::vector<std::function<void()>> possibleInputs;

	possibleInputs = AddPlayableCards(handCards, tableCard, possibleInputs);

	bool hasCardsToPlay = possibleInputs.size() > 0;
	if (hasCardsToPlay) {
		cout << "\n" << possibleInputs.size() << " - Yell UNO!" << endl;
		possibleInputs.push_back(_yellUnoInput);
	}
	else {
		possibleInputs = AddDrawCardsInput(possibleInputs);
	}

	int inputSelected = ReceiveAvailableInput(possibleInputs);
	possibleInputs[inputSelected]();

	if (HasExtraMovement) {
		possibleInputs.erase(possibleInputs.begin() + inputSelected);
		TakeExtraInputs(handCards, tableCard, possibleInputs);
	}
}

std::vector<std::function<void()>> KeyboardInputComponent::AddPlayableCards(std::vector<Card> handCards, Card tableCard, std::vector<std::function<void()>> possibleInputs) 
{
	for (int i = 0; i < handCards.size(); i++) {
		if (tableCard.IsPlayableWith(handCards[i])) {
			cout << "\n" << possibleInputs.size() << " - Play " << handCards[i].CardDisplay();
			possibleInputs.push_back([=]() {_playCardInput(handCards[i]); });
		}
	}
	return possibleInputs;
}

int KeyboardInputComponent::ReceiveAvailableInput(std::vector<std::function<void()>> possibleInputs)
{
	int input = -1;
	bool playerNumbersIsInvalid = input < 0 || input >= possibleInputs.size();

	while (playerNumbersIsInvalid) {
		cin >> input;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		playerNumbersIsInvalid = input < 0 || input >= possibleInputs.size();
	}
	return input;
}

std::vector<std::function<void()>> KeyboardInputComponent::AddDrawCardsInput(std::vector<std::function<void()>> possibleInputs)
{
	cout << endl << possibleInputs.size() << " - Draw card" << endl;
	possibleInputs.push_back(_buyCardInput);
	return possibleInputs;
}

void KeyboardInputComponent::TakeExtraInputs(std::vector<Card> handCards, Card tableCard, std::vector<std::function<void()>> possibleInputs)
{
	int inputsCount = 0;
	for (int i = 0; i < handCards.size(); i++) {
		if (tableCard.IsPlayableWith(handCards[i])) {
			cout << "\n" << inputsCount << " - Play " << handCards[i].CardDisplay();
			inputsCount++;
		}
	}
	
	HasExtraMovement = false;
	possibleInputs[ReceiveAvailableInput(possibleInputs)]();
}