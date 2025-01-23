#pragma once

#include "Component.h"
#include "ITransformableModifier.h"
#include "ITransformableViewer.h"

class ViewComponent : public Component, public ITransformableModifier, public ITransformableViewer
{
	Vector2f center;
	Vector2f size;
	View view;

public:
	FORCEINLINE void SetSize(const Vector2f& _center)
	{
		center = _center;
	}
	FORCEINLINE void SetCenter(const Vector2f& _size)
	{
		size = _size;
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		Super::SetRotation(_rotation);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override 
	{
		Super::Rotate(_angle);
	}
	FORCEINLINE Vector2f GetSize() const
	{
		return size;
	}
	FORCEINLINE Vector2f GetCenter() const
	{
		return center;
	}

public:
	ViewComponent(Actor* _owner, const Vector2f& _center, const Vector2f& _size);
	ViewComponent(Actor* _owner, ViewComponent* _other);

public:

};

