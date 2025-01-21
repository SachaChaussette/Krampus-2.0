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
	vector<Actor*> _garbage;

	using Iterator = set<Actor*>::reverse_iterator;
	for (Iterator _iterator = allActors.rbegin(); _iterator != allActors.rend(); )
	{
		Actor* _actor = *_iterator;

		_actor->Tick(_deltaTime);
		++_iterator;

		if (_actor->IsToDelete())
		{
			_garbage.push_back(_actor);
		}
	}

	for (Actor* _actor : _garbage) 
	{
		delete _actor;
	}
}

void ActorManager::BeginDestroy()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginDestroy();
	}
}

