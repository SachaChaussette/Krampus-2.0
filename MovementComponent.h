#pragma once

#include "Component.h"

class MovementComponent : public Component
{
	float speed;
	Vector2f direction;

public:
	MovementComponent(Actor* _owner);
	MovementComponent(Actor* _owner, const MovementComponent& _other);

protected:
	virtual void Tick(const float _deltaTime) override;

private: 
	void Move(const float _deltaTime);
};

