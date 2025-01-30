#pragma once
#include "Image.h"
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
		map<string, Label*> labelsByName;
		Image* background;
		TextFieledData data;
	public:
		FORCEINLINE void CreateLabel(const string& _labelName)
		{
			if (labelsByName[_labelName]) return;
			labelsByName[_labelName] = CreateSocket<Label>();
		}
		FORCEINLINE void SetLabelText(const string& _labelName, const string& _string)
		{
			if (!labelsByName.contains(_labelName)) return;
			if (!labelsByName[_labelName]) CreateLabel(_labelName);
			labelsByName[_labelName]->SetString(_string);
		}
		FORCEINLINE void SetLabelColor(const string& _labelName, const Color& _color)
		{
			if (!labelsByName.contains(_labelName)) return;
			if (!labelsByName[_labelName]) CreateLabel(_labelName);
			labelsByName[_labelName]->SetFillColor(_color);
		}
		/// <summary>
		/// Changer l'opcité de la fenetre
		/// </summary>
		/// <param name="_opavity">choisi l'oppacité entre 0 et 1 c'est le pourcentage</param>
		FORCEINLINE void SetBackgroundOpacity(const float& _opacity)
		{
			const Color& _color = background->GetFillColor();
			const uint8_t& _alpha = CAST(uint8_t, 255 * _opacity);
			background->SetFillColor(Color(_color.r, _color.g, _color.b));
		}
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
		TextField(TextField* _other);
	
	public:


		virtual void Construct() override;
		virtual void Deconstruct() override;
		virtual void Render(RenderWindow& _window) override;
		FORCEINLINE void SetLabelFont(const string& _font, const FontExtensionType& _extension);
	};
}



/*
* Label
* 
* 
* 
*/
