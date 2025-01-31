#include "Button.h"
#include <iostream>

UI::Button::Button(const string& _name, const RectangleShapeData& _data, const RenderType& _type, const ButtonData& _buttonData) : Image(_name, _data, _type)
{
	isSelected = false;
	isHovered = false;
	isHeld = false;
	foreground = nullptr;
	data = _buttonData;
}


bool UI::Button::OnPressed()
{
	isSelected = true;
	isHeld = true;

	if (data.pressedCallback)
	{
		data.pressedCallback();
		return true;
	}
	
	return false;
}

void UI::Button::OnHeld()
{
	if (!isHeld) return;

	if (data.releasedCallback)
	{
		data.releasedCallback();
	}
}

void UI::Button::OnReleased()
{
	if (!isSelected) return;

	isSelected = false;
	isHeld = false;

	if (data.heldCallback)
	{
		data.heldCallback();
	}
}

void UI::Button::OnHovered()
{
	isHovered = true;

	if (data.hoveredCallback)
	{
		data.hoveredCallback();
	}
}

void UI::Button::OnUnhovered()
{
	isHovered = false;

	if (data.unHoveredCallback)
	{
		data.unHoveredCallback();
	}
}


void UI::Button::Execute(const Event& _event)
{

}