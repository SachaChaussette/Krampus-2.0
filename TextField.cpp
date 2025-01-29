#include "TextField.h"

UI::TextField::TextField(const string& _name, const RenderType& _renderType) 
						: Widget(_name, _renderType)
{
	background = nullptr;
	labelsByName["Title"] = nullptr;
	labelsByName["PlaceHolder"] = nullptr;
	labelsByName["Description"] = nullptr;
	data = TextFieledData();
}

UI::TextField::TextField(Label* _title, Label* _placeholder, Label* _description, 
						const TextFieledData& _data, const string& _name, 
						const RenderType& _renderType) : Widget(_name, _renderType)
{
	background = nullptr;
	labelsByName["Title"] = _title;
	labelsByName["PlaceHolder"] = _placeholder;
	labelsByName["Description"] = _description;
	data = _data;
}

void UI::TextField::Construct()
{
	Super::Construct();
	background = CreateSocket<Image>(AT_SNAP_TO_TARGET, "Background", RectangleShapeData(data.size));
	SetBackgroundOpacity(0.5f); //TODO change and tweak value
	// TODO pouvoir différencier le titre, le placeolder et la description
	

	// TODO placer les Sockets à leur offset par raport au texte field
}

void UI::TextField::Deconstruct()
{
	Super::Deconstruct();

}

void UI::TextField::Render(RenderWindow& _window)
{
	const u_int& _childrensCount = CAST(u_int,GetChildren().size());
	for (u_int _index = 0; _index < _childrensCount; _index++)
	{
		Label* _label = dynamic_cast<Label*>(GetChildrenAtIndex(_index));
		_label->Render(_window);
	}
}

void UI::TextField::SetLabelFont(const string& _font, const FontExtensionType& _extensionFont)
{
	for(const pair<string, Label*>& _pairLabel : labelsByName)
	{
		if (Label* _label = _pairLabel.second)
		{
			_label->SetFont(_font, _extensionFont);
		}
	}
}
