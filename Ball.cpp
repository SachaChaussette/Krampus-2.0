#include "Ball.h"

Ball::Ball(const float _radius) : MeshActor(_radius)
{
	// Movement
	canMove = true;
	moveSpeed = 5.0f;
	direction = Vector2f();
	// Bounce
	bounceDuration = 1.0f;
	elasticity = 0.0f;
	bounceDirection = Vector2f();
	// Fall
	mass = 20.0f;
	gravity = 9.81f;
}


void Ball::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);


	// Calcule des surfaces touchées

	if (canMove)
	{
		// Direction
		const Vector2f& _directionOffset = direction * moveSpeed * 100.0f;

		// Fall
		const Vector2f& _downVector = Vector2f(0.0f, 1.0f);
		const Vector2f& _fallOffset = _downVector * gravity * mass;

		if (bounceDuration > 0.0f)
		{
			bounceDuration -= _deltaTime; // < 0
			bounceDuration = bounceDuration < 0.0f ? 0.0f : bounceDuration;
			bounceDirection *= EaseOutQuart(0.5f);
		}
		

		// Result
		const Vector2f& _offset = (_directionOffset + _fallOffset + bounceDirection) * _deltaTime;
		movement += _fallOffset * _deltaTime;
		Move(_offset);
	}
}




Vector2f Ball::ComputeRebound(const Vector2f& _direction, const Vector2f& _normal, const float _restitution)
{
	Vector2f _normalizedNormal = _normal.normalized();
	float _dotProduct = _direction.dot(_normalizedNormal);
	return _direction - _normalizedNormal * ((1 + _restitution) * _dotProduct);
}