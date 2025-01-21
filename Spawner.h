#pragma once

#include "MeshActor.h"

class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	SubclassOf<MeshActor>* actorRef;
	// TODO REMOVE
	float radius;
	size_t pointCount;
	string path;
	MeshActor actor;
public:
	Spawner(MeshActor _actor);
	Spawner(SubclassOf<MeshActor>* _actorRef);
	Spawner();
private:
	virtual void BeginPlay() override;
	void Spawn_Internal();
public:
	void Spawn(SubclassOf<MeshActor>& _actorRef);
	void Spawn(MeshActor _actor);
	void Spawn();
};

