#pragma once

#include "Component.h"
#include "MeshComponent.h"
#include "ITransformableViewer.h"
#include "ITransformableModifier.h"


class RootComponent : public Component, public ITransformableViewer, public ITransformableModifier
{
	TransformData transform;
public:
#pragma region Getter

	FORCEINLINE Vector2f GetOrigin() const override
	{
		return transform.origin;
	}
	FORCEINLINE Vector2f GetPosition() const override
	{
		return transform.position;
	}
	FORCEINLINE Angle GetRotation() const override
	{
		return transform.rotation;
	}
	FORCEINLINE Vector2f GetScale() const override
	{
		return transform.scale;
	}
	FORCEINLINE TransformData GetTransform() const override
	{
		return transform;
	}

#pragma endregion

#pragma region Setter
	FORCEINLINE void SetOrigin(const Vector2f& _origin) override
	{
		transform.origin = _origin;
	}
	FORCEINLINE void SetPosition(const Vector2f& _position) override
	{
		transform.position = _position;
	}
	FORCEINLINE void SetRotation(const Angle& _rotation) override
	{
		transform.rotation = _rotation;
	}
	FORCEINLINE void SetScale(const Vector2f& _scale) override
	{
		transform.scale = _scale;
	}
	FORCEINLINE void SetTransform(const TransformData& _transformData) override
	{
		transform.origin = _transformData.origin;
		transform.position = _transformData.position;
		transform.rotation = _transformData.rotation;
		transform.scale = _transformData.scale;
	}
	FORCEINLINE void Move(const Vector2f& _offset) override
	{
		transform.position += _offset;
	}
	FORCEINLINE void Rotate(const Angle& _angle) override
	{
		transform.rotation += _angle;
	}
	FORCEINLINE void Scale(const Vector2f& _factor) override
	{
		transform.scale += _factor;
	}

#pragma endregion

public:
	RootComponent(Actor* _owner);

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestoy() override;
};

