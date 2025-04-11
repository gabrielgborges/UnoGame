#include "CardTable.h"

void CardTable::AddPlayer(shared_ptr<Player> newPlayer)
{
	_playersInTable.push_back(newPlayer);
	_turnController->AddPlayer(newPlayer);
	newPlayer->SetBuyCardCallback(bind(&CardTable::HandleCardBuy, this, placeholders::_1));
	newPlayer->SetPlayCardCallback(bind(static_cast<void(CardTable::*)(Card,int)>(&CardTable::HandleCardDiscard), this, placeholders::_1,placeholders::_2));
	newPlayer->SetYellUnoCallback(bind(&CardTable::HandleUnoYell, this, placeholders::_1));
	float a = 2.0f;
}

void CardTable::Setup()
{
	_effectHandler->SetBuyCardsCallback([&](int amount) {HandleForcedCardBuy(amount); });
	_effectHandler->SetBuyDiscardedCardsCallback([&](int amount) {HandleForcedDiscardedCardBuy(amount); });
	_turnController->SetEffectHandler(_effectHandler);
	_deck->Shuffle();
	GiveInitialHands();
	DefineRandomPlayOrder();
	for (Card card : _deck->GetAvailableCards(1)) {
		HandleCardDiscard(card);
		cout << "\nInitial card is: " << card.CardDisplay() << "\n";
	}
}

void CardTable::StartGame()
{
	_turnController->PlayTurns();
	if (!_gameIsFinished) {
		StartGame();
	}
}

void CardTable::GiveInitialHands()
{
	for (shared_ptr<Player> player : _playersInTable) {
		player->BuyCard(_deck->GetAvailableCards(_initialHands));
	}
}

void CardTable::HandleCardDiscard(Card card)
{
	_deck->AddToDiscardPile(card);
	_turnController->SetTableCard(card);
	_effectHandler->Resolve(card.Type);
}

void CardTable::HandleCardDiscard(Card card, int playerIndex)
{
	CheckPlayerWon(playerIndex);

	_deck->AddToDiscardPile(card);
	_turnController->SetTableCard(card);

	ApplyUnoPenalties(playerIndex);
	_effectHandler->Resolve(card.Type);
}

void CardTable::HandleUnoYell(int playerIndex)
{
	cout << "\nPlayer " << playerIndex << " yelled UNO!\n";
	for (shared_ptr<Player> player : _playersInTable) {
		if (player->GetIndex() == playerIndex) {
			_playersInUNO.push_back(player);
		}
	}
}

void CardTable::ApplyUnoPenalties(int playerIndex)
{
	for (int i = 0; i < _playersInUNO.size(); i++) {
		if (_playersInUNO[i]->GetIndex() == playerIndex) {
			if (_playersInUNO[i]->CardCount() == 1) {
				cout << "\nIs correctly in UNO :)\n";
				_playersInUNO.erase(_playersInUNO.begin() + i);
				return;
			};
			cout << "\nSince he had " << _playersInUNO[i]->CardCount() << " cards, he will have to buy 2 more :)\n";
			_playersInUNO[i]->BuyCard(_deck->GetAvailableCards(_wrongUnoPenalty));
			_playersInUNO.erase(_playersInUNO.begin() + i);
			break;
		}
	}

	for (shared_ptr<Player> player : _playersInTable) {
		if (player->GetIndex() == playerIndex) {
			if (player->CardCount() == 1) {
				cout << "\nSince he had 1 card and did not say UNO, he will have to buy 2 cards :)\n";
				player->BuyCard(_deck->GetAvailableCards(_wrongUnoPenalty));
			}
			return;
		}
	}
}

void CardTable::CheckPlayerWon(int playerIndex)
{
	for (shared_ptr<Player> player : _playersInTable) {
		if (player->GetIndex() == playerIndex) {
			if (player->CardCount() == 0) {
				cout << "\nCONGRATULATIONS FOR THE PLAYER " << playerIndex << "!!! HE JUST HAVE WON THE GAME\n Thanks for playing :D\n";
				_gameIsFinished = true;
				string anything;
				cin >> anything;
				exit(0);
			}
			return;
		}
	}
}

void CardTable::DefineRandomPlayOrder()
{
	_turnController->DefineRandomTurnOrder();
}

void CardTable::HandleCardBuy(int playerIndex)
{
	auto iterator = find_if(_playersInTable.begin(), _playersInTable.end(), [playerIndex](shared_ptr<Player>& player) {
		return player->GetIndex() == playerIndex;
		});

	if (iterator != _playersInTable.end()) {
		cout << "\nPlayer " << playerIndex << " has chosen to draw " << _standardCardDraw << " card\n";
		iterator->get()->BuyCard(_deck->GetAvailableCards(_standardCardDraw));
	}
}

void CardTable::HandleForcedCardBuy(int amount)
{
	int playerIndex = _turnController->NextPlayerToPlay();
	auto iterator = find_if(_playersInTable.begin(), _playersInTable.end(), [playerIndex](shared_ptr<Player>& player) {
		return player->GetIndex() == playerIndex;
		});

	if (iterator != _playersInTable.end()) {
		iterator->get()->BuyCard(_deck->GetAvailableCards(amount));
		_turnController->SkipTurn();
	}
}

void CardTable::HandleForcedDiscardedCardBuy(int amount)
{
	int playerIndex = _turnController->NextPlayerToPlay();
	auto iterator = find_if(_playersInTable.begin(), _playersInTable.end(), [playerIndex](shared_ptr<Player>& player) {
		return player->GetIndex() == playerIndex;
		});

	if (iterator != _playersInTable.end()) {
		iterator->get()->BuyCard(_deck->GetDiscardedCards(amount));
		_turnController->SkipTurn();
	}
}
