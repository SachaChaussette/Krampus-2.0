#include "Actor.h"
#include "ActorManager.h"

Actor::Actor(const float _radius, const string& _path, const IntRect& _rect, const size_t& _pointCount)
{
	shape = new ShapeObject(_radius, _path, _rect, _pointCount);
	Register();
}

Actor::Actor(const Vector2f _size, const string& _path, const IntRect& _rect)
{
	shape = new ShapeObject(_size, _path, _rect);
	Register();
}


Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
	delete shape;
}

void Actor::Register()
{
	ActorManager::GetInstance().AddActor(this);
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

