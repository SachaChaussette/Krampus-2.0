#include "CoreMinimal.h"
#include "Game.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
    InitConfig();

    Game::GetInstance().Launch();

	return EXIT_SUCCESS;
}