#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	// Movement
	bool canMove;
	float moveSpeed;
	Vector2f direction;
	// Bounce
	float bounceDuration;
	float elasticity;
	Vector2f bounceDirection;
	// Fall
	float mass;
	float gravity;

	Vector2f movement;

public:
	FORCEINLINE void SetDirection(const Vector2f& _direction)
	{
		bounceDirection = _direction;
	}
	FORCEINLINE Vector2f GetMovement() const
	{
		return movement;
	}
	FORCEINLINE void ApplyBounce()
	{
		// Bounce
		const Vector2f _normal = Vector2f(0.0f, -1.0f);
		bounceDirection = ComputeRebound(movement, _normal, 0.8f) * gravity * mass;
		movement = Vector2f();
	}
public:
	Ball(const float _radius);

	virtual void Tick(const float _deltaTime) override;

private:
	Vector2f ComputeRebound(const Vector2f& _direction, const Vector2f& _normal, const float _restitution);

};