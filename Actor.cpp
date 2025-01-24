#include "Actor.h"
#include "ActorManager.h"
#include "TimerManager.h"

Actor::Actor(const string& _name, const float _lifeSpan, const TransformData& _transform)
{
	lifeSpan = _lifeSpan;
	name = _name;
	displayName = "Unknown";
	isToDelete = false;
	root = CreateComponent<RootComponent>(_transform);
}

Actor::Actor(const Actor& _actor)
{
	lifeSpan = _actor.lifeSpan;
	name = _actor.name;
	isToDelete = false;
	root = CreateComponent<RootComponent>(_actor.root);
}

Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
}


void Actor::Construct()
{
	id = GetUniqueID();
	//displayName = M_ACTOR.GetAvailableName(name);
	M_ACTOR.AddActor(this);
}

void Actor::Deconstruct()
{
	M_ACTOR.RemoveActor(this);
}

void Actor::BeginPlay()
{
	new Timer([&]() { Destroy(); }, seconds(lifeSpan), true);

	for (Component* _component : components)
	{
		_component->BeginPlay();
	}
}

void Actor::Tick(const float _deltaTime)
{
	for (Component* _component : components)
	{
		_component->Tick(_deltaTime);
	}
}

void Actor::BeginDestroy()
{
	for (Component* _component : components)
	{
		_component->BeginDestroy();
	}
}

void Actor::Destroy()
{
	SetToDelete();
}


void Actor::AddComponent(Component* _component)
{
	components.insert(_component);
}

void Actor::RemoveComponent(Component* _component)
{
	components.erase(_component);
}