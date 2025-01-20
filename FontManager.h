#pragma once

#include "Singleton.h"
#include "ShapeObject.h"
#include "TextObject.h"

class FontManager : public Singleton<FontManager>
{
	string defaultFontPath;
	string defaultFontExtension;
	Font* defaultFont;

public:
	FORCEINLINE Font GetDefaultFont()
	{
		if (!defaultFont)
		{
			LoadDefaultFont();
		}
		return *defaultFont;
	}
public:
	FontManager();
	~FontManager();
private:
	void LoadDefaultFont();
	void LoadFont(Font& _font, const string& _path);
	void SetFont(Text* _text, Font* _font);
	string GetExtensionNameByType(const FontExtensionType& _fontType);
public:
	void Load(TextObject* _textObject, const string& _path, const FontExtensionType& _type);


};

