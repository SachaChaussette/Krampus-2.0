#include "RootComponent.h"

RootComponent::RootComponent(Actor* _owner) : Component(_owner)
{

}

RootComponent::RootComponent(Actor* _owner, const RootComponent& _other) : Component(_owner)
{
	transform = _other.transform;
}