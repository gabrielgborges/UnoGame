#include "GameSystem.h"

int main()
{
    unique_ptr<GameSystem> gameSystem = make_unique<GameSystem>();
    gameSystem->SetupGame();
    gameSystem->StartGame();
}
