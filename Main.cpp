#include "GameManager.h"
#include "DuckHuntGame.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();

   M_GAME.Launch(new DuckHuntGame());

    /*DuckHuntGame _game;
    _game.Launch();*/

	return EXIT_SUCCESS;
}