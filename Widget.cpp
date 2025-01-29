#include "Widget.h"
#include "CameraManager.h"

using namespace Camera;

UI::Widget::Widget(const string& _name, const RenderType& _type) : Actor(_name)
{
	type = _type;
	visibility = Visible;
	renderToken = 0;
}

void UI::Widget::Construct()
{
	const RenderData& _data = RenderData(bind(&Widget::Render, this, placeholders::_1), Screen);
	renderToken = M_CAMERA.BindOnRenderWindow(_data);
}

void UI::Widget::Deconstruct()
{
	M_CAMERA.UnbindOnRenderWindow(renderToken);
}
