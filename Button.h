#pragma once
#include "Image.h"
#include <functional>

using namespace std;

namespace UI
{
	struct ButtonData
	{
		function<void()> hoveredCallback;
		function<void()> unHoveredCallback;
		function<void()> pressedCallback;
		function<void()> releasedCallback;
		function<void()> heldCallback;

		ButtonData() = default;

		ButtonData(const function<void()>& _hoveredCallback,
			const function<void()>& _unHoveredCallback,
			const function<void()>& _pressedCallback,
			const function<void()>& _releasedCallback,
			const function<void()>& _heldCallback)
		{
			hoveredCallback = _hoveredCallback;
			unHoveredCallback = _unHoveredCallback;
			pressedCallback = _pressedCallback;
			releasedCallback = _releasedCallback;
			heldCallback = _heldCallback;
		};

	};

	class Button : public Image
	{
		bool isSelected;
		bool isHeld;
		bool isHovered;
		Widget* foreground;
		ButtonData data;

	public:
		bool IsSelected() const
		{
			return isSelected;
		}
		bool IsHovered() const
		{
			return isHovered;
		}
		void SetForeground(Widget* _foreground)
		{
			foreground = _foreground;
		}
		Widget* GetForeground() const
		{
			return foreground;
		}
		ButtonData& GetData()
		{
			return data;
		}

	public:
		Button(const string& _name, const RectangleShapeData& _data, const RenderType& _type = Screen, const ButtonData& _buttonData = ButtonData());

	public:
		bool OnPressed();
		void OnHeld();
		void OnReleased();
		void OnHovered();
		void OnUnhovered();

		void Execute(const Event& _event);
	};


}