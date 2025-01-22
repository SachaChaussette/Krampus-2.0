#include "Spawner.h"
#include "TimerManager.h"
#include "Level.h"

Spawner::Spawner()
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	ref = new SubclassOf<Actor>(MeshActor(20.0f, 30, "images.jpg")); // par défaut
}

Spawner::Spawner(const Spawner& _other) : Actor(_other)
{
	spawnRate = _other.spawnRate;
	spawnRange = _other.spawnRange;
	ref = new SubclassOf<Actor>(*_other.ref);
}

Spawner::~Spawner()
{
	delete ref;
}


void Spawner::BeginPlay()
{
	Super::BeginPlay();
	new Timer<Seconds>([&]() { Spawn(); }, Time(seconds(spawnRate)), true, true);
}

void Spawner::Spawn()
{
	LOG(Display, "Spawn");

	const Vector2f& _spawnPosition =
	{
		GetRandomNumberInRange(0.0f, spawnRange),
		GetRandomNumberInRange(0.0f, spawnRange),
	};
	ref->GetSubclassObject().SetPosition(_spawnPosition);

	Level::SpawnActor<Actor>(*ref);
}