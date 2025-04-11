#pragma once
#include "InputComponentBase.h"

using namespace std;
class KeyboardInputComponent : public InputComponentBase
{
public:
	KeyboardInputComponent();
	void ChooseInput(const std::vector<Card> handCards, const Card tableCard) override;
	std::vector<std::function<void()>> AddPlayableCards(std::vector<Card> handCards, Card tableCard, std::vector<std::function<void()>> possibleInputs);
	~KeyboardInputComponent() override = default;

protected:
	void TakeExtraInputs(std::vector<Card> handCards, Card tableCard, std::vector<std::function<void()>> possibleInputs) override;

private:
	int ReceiveAvailableInput(std::vector<std::function<void()>> possibleInputs);

	std::vector<std::function<void()>> AddDrawCardsInput(std::vector<std::function<void()>> possibleInputs);
};

