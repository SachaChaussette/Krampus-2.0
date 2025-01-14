#include "TextureManager.h"

TextureManager::TextureManager()
{
	defaultTexturePath = "MissingTexture";
	defaultExtensionPath = "png";
	defaultTexture = nullptr;
}

TextureManager::~TextureManager()
{
	delete defaultTexture;
}

void TextureManager::LoadDefaultTexture()
{
	const string& _finalPath = defaultTexturePath + "." + defaultExtensionPath;
	defaultTexture = new Texture();
	LoadTexture(*defaultTexture, _finalPath);
}

void TextureManager::LoadTexture(Texture& _texture, const string& _path)
{
	const string& _finalPath = "Assets/Textures/" + _path;
	if (!_texture.loadFromFile(_finalPath))
	{
		DISPLAY_ERROR("Error => Cannot open file with following path : \'" + _path + "\' !", true);
		_texture = GetDefaultTexture();
	}
}

void TextureManager::SetTexture(Shape* _shape, const Texture* _texture)
{
	_shape->setTexture(_texture);
}
void TextureManager::SetTextureFromRect(Shape* _shape, const IntRect& _rect)
{
	_shape->setTextureRect(_rect);
}

void TextureManager::Load(ShapeObject* _shapeObject, const string& _path, 
						const IntRect& _rect,const bool _isRepeated, const bool _smooth)
{
	Texture& _texture = _shapeObject->GetTexture();
	if (_path.empty())
	{
		DISPLAY_ERROR("Error => Cannot open file with an empty path", true);
		_texture = GetDefaultTexture();
	}

	// Init Texture
	LoadTexture(_texture, _path);
	_texture.setRepeated(_isRepeated);
	_texture.setSmooth(_smooth);

	// Apply Texture
	if (_rect == IntRect())
	{
		SetTexture(_shapeObject->GetDrawable(), &_texture);
	}
	else
	{
		SetTextureFromRect(_shapeObject->GetDrawable(),  _rect);
	}

}
