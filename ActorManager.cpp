#include "ActorManager.h"

ActorManager::~ActorManager()
{
	for (Actor* _actor : allActors)
	{
		delete _actor;
	}
}

void ActorManager::BeginPlay()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginPlay();
	}
}

void ActorManager::Tick(const float _deltaTime)
{
	using Iterator = set<Actor*>::iterator;
	for (Iterator _iterator = allActors.begin(); _iterator != allActors.end(); )
	{
		Actor* _actor = *_iterator;

		_actor->Tick(_deltaTime);
		++_iterator;
	}
}

void ActorManager::BeginDestoy()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginDestoy();
	}
}

