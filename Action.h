#pragma once

#include "CoreMinimal.h"

namespace Input
{
	typedef optional<Event> EventInfo;

	enum ControllerButtonsType
	{
		Start,
		Select,
		Cross,
		Circle,
		Triangle,
		Square,
		L1,
		R1,
		L2,
		R2,
		LeftStick,
		RightStick,
	};

	enum ControllerAxesType
	{
		LeftStickX,
		LeftStickY,
		RightStickX,
		RightStickY,
	};

	enum ValueType
	{
		Digital,	// bool
		Axis,		// float
		Axis2,		// Vector2f
	};


	struct ActionData
	{
		ValueType type;
		type_index trigger;

		int key;
		ControllerButtonsType buttonsType;
		ControllerAxesType axesType;
	};

	class Action
	{
		string name;
		ActionData data;
		set<int> inputs;
		function<void()> callback;

	public:
		void TryToExecute(const EventInfo& _event)
		{
			type_index _type = typeid(_event.value());

			if (data.trigger == _type)
			{
				callback();
			}
		}
	};


}

