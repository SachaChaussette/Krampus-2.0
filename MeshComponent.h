#pragma once

#include "Component.h"
#include "ShapeObject.h"

class MeshComponent : public Component
{
	ShapeObject* shape;
public:
	FORCEINLINE ShapeObject* GetShape() const
	{
		return shape;
	}
	FORCEINLINE void SetShape(ShapeObject* _shape)
	{
		shape = _shape;
	}
	FORCEINLINE Vector2f GetOrigin() const
	{
		return shape->GetDrawable()->getOrigin();
	}
	FORCEINLINE Vector2f GetPosition() const
	{
		return shape->GetDrawable()->getPosition();
	}
	FORCEINLINE Angle GetRotation() const
	{
		return shape->GetDrawable()->getRotation();
	}
	FORCEINLINE Vector2f GetScale() const
	{
		return shape->GetDrawable()->getScale();
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin)
	{
		shape->GetDrawable()->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position)
	{
		shape->GetDrawable()->setPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation)
	{
		shape->GetDrawable()->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale)
	{
		shape->GetDrawable()->setScale(_scale);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset)
	{
		shape->GetDrawable()->move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		shape->GetDrawable()->rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor)
	{
		shape->GetDrawable()->scale(_factor);
	}
public:
	MeshComponent(Actor* _owner, const float _radius, const size_t& _pointCount = 30,
		const string& _path = "", const IntRect& _rect = IntRect());
	MeshComponent(Actor* _owner, const Vector2f _size, const string& _path, const IntRect& _rect = IntRect());
	MeshComponent(Actor* _owner, const MeshComponent& _other);
	virtual ~MeshComponent() override;
};

