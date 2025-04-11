#pragma once
#include "InputComponentBase.h"
#include <random>

class AiInputComponent : public InputComponentBase
{
public:
	AiInputComponent();
	void ChooseInput(const std::vector<Card> handCards, const Card tableCard) override;
	~AiInputComponent() override = default;
protected:
	void TakeExtraInputs(std::vector<Card> handCards, Card tableCard, std::vector<std::function<void()>> possibleInputs) override;

private:
	std::default_random_engine generator;

};

