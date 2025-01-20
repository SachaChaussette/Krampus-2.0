#include "FontManager.h"

FontManager::FontManager()
{
	defaultFontPath = "DefaultFont";
	defaultFontExtension = "ttf";
	defaultFont = nullptr;
}

FontManager::~FontManager()
{
	delete defaultFont;
}

void FontManager::LoadDefaultFont()
{
	const string& _finalPath = defaultFontPath + "." + defaultFontExtension;
	defaultFont = new Font("Assets/Fonts/" + _finalPath);
}

void FontManager::LoadFont(Font& _font, const string& _path)
{
	const string& _finalPath = "Assets/Fonts/" + _path;

	if (!_font.openFromFile(_finalPath))
	{
		LOG(Error, "Cannot open file with following path : \'" + _path + "\' !");
		_font = GetDefaultFont();
	}
}

void FontManager::SetFont(Text* _text, Font* _font)
{
	_text->setFont(*_font);
}

string FontManager::GetExtensionNameByType(const FontExtensionType& _fontType)
{
	const string _extensionNames[] =
	{ 
		"otf",
		"ttf", 
	};
	return _extensionNames[_fontType];
}

void FontManager::Load(TextObject* _textObject, const string& _path, const FontExtensionType& _type)
{
	Font& _font = _textObject->GetFont();

	if (_path.empty())
	{
		LOG(Error, "Cannot open file with an empty path");
		_font = GetDefaultFont();
	}

	// Init
	const string& _fontPath = _path + "." + GetExtensionNameByType(_type);
	LoadFont(_font, _fontPath);

	SetFont(_textObject->GetDrawable(), &_font);

}
