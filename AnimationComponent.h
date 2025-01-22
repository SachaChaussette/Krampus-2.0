#pragma once

#include "Component.h"
#include "Animation.h"

class AnimationComponent : public Component
{
	Animation* current;
	map<string, Animation*> allAnimations;

public:
	FORCEINLINE void SetCurrentAnimation(const string& _name)
	{
		if (!allAnimations.contains(_name)) return;
		current = allAnimations[_name];
	}
	FORCEINLINE void StartAnimation()
	{
		if (!current) return;
		current->Start();
	}
public:
	AnimationComponent(Actor* _owner);
	AnimationComponent(Actor* _owner, AnimationComponent* _other);
	~AnimationComponent();

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override {};
	virtual void BeginDestroy() override {};

	void AddAnimation(Animation* _animation);
	void AddAnimations(const vector<Animation*>& _animations);
};

