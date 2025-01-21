#pragma once
#include "Actor.h"
#include "MeshActor.h"
#include "Label.h"

class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	SubclassOf<Actor>* ref;

public:
	Spawner();
	Spawner(const Spawner& _other);
	~Spawner();

private:
	virtual void BeginPlay() override;
	void Spawn();
};

