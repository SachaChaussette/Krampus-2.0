#pragma once

#include "MeshActor.h"
#include "MovementComponent.h"

class Duck : public MeshActor
{
	float lifeSpan;
	MovementComponent* movement;
public:
	Duck(const Vector2f& _size, const string& _path, const IntRect& _rect);
	Duck(const Duck& _other);

protected:
	virtual void BeginPlay() override;
};

