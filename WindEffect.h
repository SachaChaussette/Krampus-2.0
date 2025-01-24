#pragma once
#include "MeshActor.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class WindEffect : public MeshActor
{
	AnimationComponent* animation;

public:
	WindEffect(const Vector2f& _size, const string& _path = "", const IntRect& _rect = {});
	WindEffect(const WindEffect& _other);

protected:
	virtual void BeginPlay() override;
public:
	virtual void Construct() override;
	virtual void Deconstruct() override;
};