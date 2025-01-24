#pragma once
#include "Singleton.h"
#include "ShapeObject.h"

class TextureManager : public Singleton<TextureManager>
{
	string defaultTexturePath;
	string defaultTextureExtension;
	Texture* defaultTexture;

private:
	FORCEINLINE Texture GetDefaultTexture()
	{
		if (!defaultTexture)
		{
			LoadDefaultTexture();
		}

		return *defaultTexture;
	}

public:
	TextureManager();
	~TextureManager();

private:
	void LoadDefaultTexture();
	void LoadTexture(Texture& _texture, const string& _path, const IntRect& _rect = IntRect());
	void SetTexture(Shape* _shape, const Texture* _texture);
	string GetExtensionNameByType(const TextureEnum::ExtensionType& _textureType);

public:
	void Load(ShapeObject* _shapeObject, const string& _path, const TextureEnum::ExtensionType& _textureType = PNG,
			  const IntRect& _rect = IntRect(), const bool _isRepeated = false, const bool _smooth = true);
	void Load(ShapeObject* _shapeObject, const string& _path, const IntRect& _rect = IntRect(),
			  const TextureEnum::ExtensionType& _textureType = TextureEnum::PNG, const bool _isRepeated = false, const bool _isSmooth = true);
	void SetTextureRect(Shape* _shape, const Vector2i& _start, const Vector2i& _size);
	void SetTextureRect(Shape* _shape, const IntRect& _rect);
};