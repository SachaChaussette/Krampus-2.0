#include "TextField.h"

UI::TextField::TextField(const string& _name, const RenderType& _renderType) 
						: Widget(_name, _renderType)
{
	title = nullptr;
	placeholder = nullptr;
	description = nullptr;
	data = TextFieledData();
}

UI::TextField::TextField(Label* _title, Label* _placeholder, Label* _description, 
						const TextFieledData& _data, const string& _name, 
						const RenderType& _renderType) : Widget(_name, _renderType)
{
	title = _title;
	placeholder = _placeholder;
	description = _description;
	data = _data;
}

void UI::TextField::Construct()
{
	Super::Construct();

	// TODO pouvoir différencier le titre, le placeolder et la description

	CreateSocket<Label>();
	CreateSocket<Label>();
	CreateSocket<Label>();

	// TODO placer les Sockets à leur offset par raport au texte field
}

void UI::TextField::Deconstruct()
{
	Super::Deconstruct();

}

void UI::TextField::Render(RenderWindow& _window)
{
	const u_int& _childrensCount = GetChildren().size();
	for (u_int _index = 0; _index < _childrensCount; _index++)
	{
		Label* _label = dynamic_cast<Label*>(GetChildrenAtIndex(_index));
		_label->Render(_window);
	}
}
