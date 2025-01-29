#pragma once
#include "Widget.h"
#include "ShapeObject.h"

namespace UI
{
	struct Gradient
	{
		Color topLeft;
		Color topRight;
		Color bottomLeft;
		Color bottomRight;

		Gradient(const Color& _topLeft = Color(), const Color& _topRight = Color(),
			const Color& _bottomLeft = Color(), const Color& _bottomRight = Color())
		{
			topLeft = _topLeft;
			topRight = _topRight;
			bottomLeft = _bottomLeft;
			bottomRight = _bottomRight;
		}
	};

	class Image : public Widget
	{
		ShapeObject* image;

		bool sizeToContent;
		Vector2f initialSize;
		VertexArray gradient;
		Gradient colorGradient;

	public:
		FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
		{
			Super::SetPosition(_position);
			image->SetPosition(_position);
		}
		FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
		{
			Super::SetRotation(_rotation);
			image->SetRotation(_rotation);
		}
		FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
		{
			Super::SetScale(_scale);
			image->SetScale(_scale);
		}
		FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
		{
			Super::SetOrigin(_origin);
			image->SetOrigin(_origin);
		}
		FORCEINLINE virtual void Move(const Vector2f& _offset) override
		{
			Super::Move(_offset);
			image->Move(_offset);
		}
		FORCEINLINE virtual void Rotate(const Angle& _angle) override
		{
			Super::Rotate(_angle);
			image->Rotate(_angle);
		}
		FORCEINLINE virtual void Scale(const Vector2f& _factor) override
		{
			Super::Scale(_factor);
			image->Scale(_factor);
		}
		FORCEINLINE virtual void SetFillColor(const Color& _color)
		{
			image->GetDrawable()->setFillColor(_color);
		}
		FORCEINLINE virtual Color GetFillColor() const
		{
			return image->GetDrawable()->getFillColor();
		}
		FORCEINLINE Vector2f GetSize() const
		{
			return image->GetDrawable()->getScale();
		}
		FORCEINLINE Vector2f GetPosition() const
		{
			return image->GetDrawable()->getPosition();
		}


	public:
		Image(const string& _name, const RectangleShapeData& _data, const RenderType& _type = Screen);

	private:
		void UpdateSize();
		void UpdateGradient();

	public:
		virtual void Render(RenderWindow& _window) override;
		void SetSizeToContent(const bool _status);
		void SetGradient(const Gradient& _gradient);
	};
}

