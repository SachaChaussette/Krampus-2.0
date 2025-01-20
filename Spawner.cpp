#include "Spawner.h"
#include "TimerManager.h"

Spawner::Spawner()
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	actorRef = new SubclassOf<MeshActor>();
}

Spawner::Spawner(SubclassOf<MeshActor>* _actorRef)
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	actorRef = _actorRef;
}

/*
*
*		TSoftObjectPtr	=> prefab déjà initialiser
*		TObjectPtr		=> pointeur originel
*		TSubclassOf		=> prefab
* 
*/



void Spawner::BeginPlay()
{
	Super::BeginPlay();
	new Timer<Seconds>(bind(&Spawner::Spawn, this), Time(seconds(spawnRate)),true,true);
}

void Spawner::Spawn_Internal()
{
	Spawn(*actorRef);
}

void Spawner::Spawn(SubclassOf<MeshActor>& _actorRef)
{
	LOG(Display, "aled");
	Actor* _actor = new Actor(actorRef->GetSubclassObject());
	const Vector2f& _spawnPosition =
	{
		GetRandomNumberInRange(0.0f, spawnRange),
		GetRandomNumberInRange(0.0f, spawnRange),
	};
	_actor->SetPosition(_spawnPosition);
}
