#pragma once

#include "Object.h"

class ShapeObject : public Object
{
	Shape* shape;
	Texture texture;


public:
	FORCEINLINE Texture& GetTexture()
	{
		return texture;
	}
	FORCEINLINE virtual Shape* GetDrawable() const override
	{
		return shape;
	} 
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		shape->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		shape->setPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		shape->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		shape->setScale(_scale);
	}
	FORCEINLINE virtual void SetTransform(const TransformData& _transformData) override
	{
		shape->setOrigin(_transformData.origin);
		shape->setPosition(_transformData.position);
		shape->setRotation(_transformData.rotation);
		shape->setScale(_transformData.scale);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		shape->move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		shape->rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		shape->scale(_factor);
	}
public:
	ShapeObject(const float _radius, const string& _path, const IntRect& _rect = IntRect(), 
				const size_t& _pointCount = 30);	// Circle
	ShapeObject(const Vector2f _size, const string& _path, const IntRect& _rect = IntRect());			// Rectangle
	virtual ~ShapeObject() override;
public:

};

