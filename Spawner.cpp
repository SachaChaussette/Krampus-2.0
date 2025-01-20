#include "Spawner.h"
#include "TimerManager.h"

Spawner::Spawner()
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	actorRef = new Actor();
}

Spawner::Spawner(Actor* _actorRef, const float _spawnRate, const float _spawnRange)
{
	spawnRate = _spawnRate;
	spawnRange = _spawnRange;
	actorRef = _actorRef;
}

Spawner::~Spawner()
{
	delete actorRef;
}

void Spawner::BeginPlay()
{
	Super::BeginPlay();
	new Timer<Seconds>(bind(&Spawner::Spawn, this), Time(seconds(spawnRate)),true,true);
}

void Spawner::Spawn()
{
	LOG(Display, "aled");
	Actor* _actor = new Actor(*actorRef);
	const Vector2f& _spawnPosition =
	{
		GetRandomNumberInRange(0.0f, spawnRange),
		GetRandomNumberInRange(0.0f, spawnRange),
	};
	_actor->SetPosition(_spawnPosition);
}
