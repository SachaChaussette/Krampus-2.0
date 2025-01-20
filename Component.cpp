#include "Component.h"

Component::Component(Actor* _owner)
{
	owner = _owner;
}

Component::~Component()
{
}

void Component::Tick(const float _deltaTime)
{
}
