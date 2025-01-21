#include "Spawner.h"
#include "TimerManager.h"

Spawner::Spawner(MeshActor _actor)
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	// TODO REMOVE
	actor = _actor;
	radius = 50.0f;
	pointCount = 30;
	path = "images.jpg";
	//actorRef = new SubclassOf<MeshActor>(50.0f, 30, );
	//Register();
}

Spawner::Spawner(SubclassOf<MeshActor>* _actorRef)
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	actorRef = _actorRef;
}

Spawner::Spawner()
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	radius = 50.0f;
	pointCount = 30;
	path = "images.jpg";

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
	new Timer([&]() { Spawn(); }, Time(seconds(spawnRate)), true, true);
}

void Spawner::Spawn_Internal()
{
	Spawn(*actorRef);
}

void Spawner::Spawn(SubclassOf<MeshActor>& _actorRef)
{
	LOG(Display, "aled");
	MeshActor* _actor = new MeshActor(actorRef->GetSubclassObject());
	const Vector2f& _spawnPosition =
	{
		GetRandomNumberInRange(0.0f, spawnRange),
		GetRandomNumberInRange(0.0f, spawnRange),
	};
	_actor->SetPosition(_spawnPosition);
}

void Spawner::Spawn(MeshActor _actor)
{
	LOG(Display, "aled");
	MeshActor* _actorPtr = new MeshActor(_actor);
	const Vector2f& _spawnPosition =
	{
		GetRandomNumberInRange(0.0f, spawnRange),
		GetRandomNumberInRange(0.0f, spawnRange),
	};
	_actorPtr->SetPosition(_spawnPosition);
}

void Spawner::Spawn()
{
	LOG(Display, "aled");
	MeshActor* _actorPtr = new MeshActor(radius, pointCount, path);
	const Vector2f& _spawnPosition =
	{
		GetRandomNumberInRange(0.0f, spawnRange),
		GetRandomNumberInRange(0.0f, spawnRange),
	};
	_actorPtr->SetPosition(_spawnPosition);
}
