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

	using Iterator = set<Actor*>::iterator;
	for (Iterator _iterator = allActors.begin(); _iterator != allActors.end(); )
	{
		Actor* _actor = *_iterator;

		++_iterator;
		if (_actor->IsToDelete())
		{
			_garbage.push_back(_actor);
			continue;
		}
		_actor->Tick(_deltaTime);

		
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

