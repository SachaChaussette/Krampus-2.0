#pragma once

#include "Actor.h"

class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	Actor* actorRef;
public:
	Spawner();
	Spawner(Actor* _actorRef, const float _spawnRate, const float _spawnRange);
	~Spawner();
private:
	virtual void BeginPlay() override;
public:
	void Spawn();
};

