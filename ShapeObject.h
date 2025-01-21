#pragma once

#include "Object.h"

// TODO IMPLEMENTER
enum TextureExtensionType
{
	PNG,
	JPG,
	GIF,
};

enum ShapeObjectType
{
	SOT_CIRCLE,
	SOT_RECTANGLE,
};

struct CircleShapeObjectData
{
	float radius;
	string path;
	IntRect rect;
	size_t pointCount;
	CircleShapeObjectData(const float _radius, const string& _path, const IntRect& _rect, const size_t& _pointCount)
	{
		radius = _radius;
		path = _path;
		rect = _rect;
		pointCount = _pointCount;
	}
	CircleShapeObjectData& operator = (const CircleShapeObjectData& _other)
	{
		radius = _other.radius;
		path = string(_other.path);
		rect = _other.rect;
		pointCount = _other.pointCount;
		return *this;
	}
};

struct RectangleShapeObjectData
{
	Vector2f size;
	string path;
	IntRect rect;
	RectangleShapeObjectData(const Vector2f _size, const string& _path, const IntRect& _rect)
	{
		size = _size;
		path = _path;
		rect = _rect;
	}

	
};

union ObjectData
{
	CircleShapeObjectData circleData;
	RectangleShapeObjectData rectangleData;

	ObjectData() {};
	~ObjectData() {};
};

struct ShapeObjectData
{
	ShapeObjectType type;
	ObjectData data;

	ShapeObjectData()
	{
		type = SOT_CIRCLE;
	}
	ShapeObjectData(const ShapeObjectType& _type, const CircleShapeObjectData& _circleData)
	{
		type = _type;
		data.circleData = _circleData;
	}
	ShapeObjectData(const ShapeObjectType& _type, const RectangleShapeObjectData& _rectangleData)
	{
		type = _type;
		data.rectangleData = _rectangleData;
	}

	ShapeObjectData& operator = (const ShapeObjectData& _other)
	{
		type = _other.type;
		if (type == SOT_CIRCLE)
		{
			data.circleData = _other.data.circleData;
		}
		else if (type == SOT_RECTANGLE)
		{
			data.rectangleData = _other.data.rectangleData;
		}
		return *this;
	}
};

class ShapeObject : public Object
{
	Shape* shape;
	Texture texture;
	ShapeObjectData objectData;

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
	ShapeObject(const ShapeObject& _other);			
	virtual ~ShapeObject() override;
private:
	void InitCircle(const CircleShapeObjectData& _data);
	void InitRectangle(const RectangleShapeObjectData& _data);
};

