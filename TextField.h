#pragma once

#include "Label.h"

namespace UI
{
	enum ContainerType
	{
		Contained,
		Outilined,
		Underlined
	};

	enum InputState
	{
		IS_Enabled,
		IS_Disabled,
		IS_Error,
	};

	enum TypingState
	{
		Placeholder,
		OnFocus,
		OnTyping,
		Typed,
	};

	struct TextFieledData
	{
		Vector2f size;
		InputState inputState;
		TypingState typingState;
		ContainerType type;
		bool isRequired;

		TextFieledData() = default;

		TextFieledData(const Vector2f& _size, const ContainerType& _type = Contained,
			const InputState& _inputState = IS_Enabled, const bool _isRequired = false)
		{
			size = _size;
			type = _type;
			inputState = _inputState;
			isRequired = _isRequired;
			typingState = Placeholder;
		}
	};

	class TextField : public Widget
	{
		//// Textes
		//Label* title;
		//Label* placeholder;
		//Label* description;

		TextFieledData data;
	public:
		FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
		{
			Super::SetPosition(_position);
		/*	title->Move();
			placeholder->Move();
			description->Move();*/
		}
	public:
		TextField(const string& _name = "TextField", const RenderType& _renderType = Screen);
		TextField(Label* _title, Label* _placeholder, Label* _description, const TextFieledData& _data,
			const string& _name = "TextField", const RenderType& _renderType = Screen);
	public:


		virtual void Construct() override;
		virtual void Deconstruct() override;
		virtual void Render(RenderWindow& _window) override;
	};
}



/*
* Label
* 
* 
* 
*/
