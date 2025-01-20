#pragma once

#include "MeshActor.h"

class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	SubclassOf<MeshActor>* actorRef;
public:
	Spawner();
	Spawner(SubclassOf<MeshActor>* _actorRef);
private:
	virtual void BeginPlay() override;
	void Spawn_Internal();
public:
	void Spawn(SubclassOf<MeshActor>& _actorRef);
};

