#include "Label.h"
#include "Game.h"

Label::Label(const string& _text, const string& _path, const FontExtensionType& _fontType)
{
	text = new TextObject(_text, _path, _fontType);
	textToken = M_GAME.BindOnRenderWindow(bind(&Label::RenderText, this, placeholders::_1));
}

Label::~Label()
{
	delete text;
}

void Label::RenderText(RenderWindow& _window)
{
	_window.draw(*text->GetDrawable());
}

