#include "Actor.h"
#include "ActorManager.h"

Actor::Actor()
{
	root = CreateComponent<RootComponent>();
	Construct();
}

Actor::Actor(const Actor& _actor)
{
	root = CreateComponent<RootComponent>();
	Construct();
}

Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
}

void Actor::BeginPlay()
{
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

void Actor::BeginDestoy()
{
	for (Component* _component : components)
	{
		_component->BeginDestoy();
	}
}

void Actor::Deconstruct()
{
	M_ACTOR.RemoveActor(this);
}

void Actor::Construct()
{
	M_ACTOR.AddActor(this);
}

void Actor::AddComponent(Component* _component)
{
	// TODO réparer
	//if (GetComponent<decltype(_component)>()) return;
	components.insert(_component);
}

void Actor::RemoveComponent(Component* _component)
{
	components.erase(_component);
}

