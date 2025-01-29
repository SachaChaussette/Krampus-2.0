#pragma once

#include "Actor.h"
#include "RenderType.h"

namespace UI
{
	enum VisibilityType
	{
		Hidden,
		Collapsed,
		Disabled,
		UninteractibleSelf,
		UninteractibleSelfAndChildren,
		Visible,
	};

	class Widget : public Actor
	{
		RenderType type;
		u_int renderToken;
	protected:
		VisibilityType visibility;

	public:
		FORCEINLINE void SetVisibility(const VisibilityType _visibility)
		{
			visibility = _visibility;
		}
	public:
		Widget(const string& _name, const RenderType& _type = Screen);

		virtual void Construct() override;
		virtual void Deconstruct() override;
		virtual void Render(RenderWindow& _window) = 0;
	};

}
