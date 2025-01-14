#pragma once

#include "Singleton.h"
#include "ShapeObject.h"

class TextureManager : public Singleton<TextureManager>
{
	string defaultTexturePath;
	string defaultExtensionPath;
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
	void LoadTexture(Texture& _texture, const string& _path);
	void SetTexture(Shape* _shape, const Texture* _texture);
	void SetTextureFromRect(Shape* _shape, const IntRect& _rect = IntRect());
public:
	void Load(ShapeObject* _shapeObject, const string& _path, const IntRect& _rect = IntRect(),
			  const bool _isRepeated = false, const bool _smooth = true);

};

