#include "Spawner.h"

Spawner::Spawner()
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	ref = nullptr;
}

Spawner::~Spawner()
{
	//delete ref;
}

void Spawner::BeginPlay()
{
	Super::BeginPlay();
	new Timer([&]() { Spawn_Internal(); }, Time(seconds(spawnRate)), true, true);
}

void Spawner::Spawn_Internal()
{
	//Spawn(*ref);
}