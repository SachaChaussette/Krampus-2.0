#include "GameManager.h"


GameManager::~GameManager()
{
	delete currentGame;
}

void GameManager::Launch(Game* _currentGame)
{
	currentGame = _currentGame;
	if (!currentGame) return;

	currentGame->Start();
	while(!currentGame->Update());
	currentGame->Stop();


}
