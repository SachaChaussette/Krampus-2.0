#include "AnimationComponent.h"
#include "MeshComponent.h"
#include "TextureManager.h"
#include "Actor.h"

AnimationComponent::AnimationComponent(Actor* _owner) : Component(_owner)
{
	current = nullptr;
	allAnimations = map<string, Animation*>();
}

AnimationComponent::AnimationComponent(Actor* _owner, AnimationComponent* _other) : Component(_owner)
{
	for (pair<string, Animation*> _animation : _other->allAnimations)
	{
		allAnimations[_animation.first] = new Animation(*_animation.second);
	}
	if(_other->current)
	{
		current = allAnimations[_other->current->GetName()];
	}
	else
	{
		current = nullptr;
	}
}

AnimationComponent::~AnimationComponent()
{
	for (pair<string, Animation*> _animation : allAnimations)
	{
		delete _animation.second;
	}
}

void AnimationComponent::BeginPlay()
{
	current->Start();
}

void AnimationComponent::AddAnimation(Animation* _animation)
{
	const string& _animationName = _animation->GetName();
	if (allAnimations.contains(_animationName)) return;

	allAnimations[_animationName] = _animation;
}

void AnimationComponent::AddAnimations(const vector<Animation*>& _animations)
{
	const u_int& _animationCount = CAST(u_int, _animations.size());
	for (u_int _index = 0; _index < _animationCount; _index++)
	{
		AddAnimation(_animations[_index]);
	}
}

