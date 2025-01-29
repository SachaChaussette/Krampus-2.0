#include "Label.h"
#include "CameraManager.h"
#include "FontManager.h"

UI::Label::Label(const string& _text, const RenderType& _type, const string& _path,
				const FontExtensionType& _fontType) : Widget("Label", _type)
{
	text = new TextObject(_text, _path, _fontType);
}

UI::Label::~Label()
{
	delete text;
}

void UI::Label::Render(RenderWindow& _window)
{
	_window.draw(*text->GetDrawable());
}

void UI::Label::SetFont(const string& _font, const FontExtensionType& _fontExtension)
{
	M_FONT.Load(text, _font, _fontExtension);
}
