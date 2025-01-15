#include "CoreMinimal.h"
#include "Game.h"
#include "TimerManager.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
    InitConfig();

    //using GAME = Game::GetInstance();

    //Game::GetInstance().Launch();

    LOG(Error, "Erreur");
    LOG(Warning, "Attention");
    LOG(Display, "Affichage");
    LOG(Log, "Enregistrement");
    LOG(Log, "Aled");
    LOG(Fatal, "Fatal Error");
   

	return EXIT_SUCCESS;
}

/*EXERCICE_MAISON:
* 
* Avoir le code à jour ✔
* Custom exception ❌
* Trouver une solution pourque Logger est tous ce qui à été déclaré dans le CoreMinimal ❌
* Faire le WriteInLogs
* Faire un panel un présentation des Logs ✔
* SoundManager::GetInstance() en SoundManager. ❌
* Utiliser le TimerManager pour avoir le temps des logs ✔
* 
*/