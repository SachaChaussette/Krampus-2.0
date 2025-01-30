#include "TextField.h"

UI::TextField::TextField(const string& _name, const RenderType& _renderType) 
						: Widget(_name, _renderType)
{
	background = nullptr;
	CreateLabel("Title");
	CreateLabel("PlaceHolder");
	CreateLabel("Description");
	data = TextFieledData();
	background = CreateSocket<Image>(AT_SNAP_TO_TARGET, "Background", RectangleShapeData(data.size));
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
	background = CreateSocket<Image>(AT_SNAP_TO_TARGET, "Background", RectangleShapeData(data.size));
}

UI::TextField::TextField(TextField* _other) : Widget(_other->GetName(), Screen)
{
	background = _other->background;
	labelsByName = _other->labelsByName;
	data = _other->data;
}

void UI::TextField::Construct()
{
	Super::Construct();

	// Preset 1
	labelsByName["Title"]->SetPosition(GetPosition());
	labelsByName["Title"]->SetScale({ 0.4f, 0.4f });
	labelsByName["PlaceHolder"]->SetPosition({5.0f, 25.0f});
	labelsByName["PlaceHolder"]->SetScale({ 0.5f, 0.5f });
	labelsByName["Description"]->SetPosition({0.0f, 55.0f});
	labelsByName["Description"]->SetScale({ 0.3f, 0.3f });
	background->SetVisibility(Visible);
	SetBackgroundOpacity(0.5f); 

	
	
}

void UI::TextField::Deconstruct()
{
	Super::Deconstruct();

}

void UI::TextField::Render(RenderWindow& _window)
{
	for (pair<string, Label*> _label : labelsByName)
	{
		_label.second->Render(_window);
	}
	background->Render(_window);
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
