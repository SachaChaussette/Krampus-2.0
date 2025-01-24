#include "ShapeObject.h"
#include "TextureManager.h"

using namespace MyTexture;

ShapeObject::ShapeObject(const float _radius, const string& _path, const IntRect& _rect,
						 const size_t& _pointCount)
{
	objectData = ShapeObjectData(CIRCLE, CircleShapeData(_radius, _path, _rect, _pointCount));
	InitCircle(*objectData.data.circleData);
}

ShapeObject::ShapeObject(const Vector2f& _size, const string& _path, const ExtensionType& _textureType, const IntRect& _rect)
{
	objectData = ShapeObjectData(RECTANGLE, RectangleShapeData(_size, _path, _textureType, _rect));
	InitRectangle(*objectData.data.rectangleData);
}

ShapeObject::ShapeObject(const ShapeObject& _other)
{
	objectData = _other.objectData;

	if (objectData.type == CIRCLE)
	{
		InitCircle(*objectData.data.circleData);
	}

	else if (objectData.type == RECTANGLE)
	{
		InitRectangle(*objectData.data.rectangleData);
	}
}

ShapeObject::~ShapeObject()
{
	delete shape;
}


void ShapeObject::InitCircle(const CircleShapeData& _data)
{
	shape = new CircleShape(_data.radius, _data.pointCount);
	M_TEXTURE.Load(this, _data.path, _data.rect);
}

void ShapeObject::InitRectangle(const RectangleShapeData& _data)
{
	shape = new RectangleShape(_data.size);
	M_TEXTURE.Load(this, _data.path, _data.rect, _data.textureType);
}