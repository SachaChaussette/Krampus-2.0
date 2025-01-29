#include "HUD.h"

UI::HUD::HUD()
{
	allWidgets = set<Widget*>();
	currentWidget = nullptr;
}

UI::HUD::~HUD()
{
	for (Widget* _widget : allWidgets)
	{
		delete _widget;
	}
}

void UI::HUD::AddToViewport()
{
}

void UI::HUD::RemoveFromViewport()
{
}
