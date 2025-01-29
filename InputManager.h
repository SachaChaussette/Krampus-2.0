#pragma once

#include "Singleton.h"
#include "ActionMap.h"

namespace Input
{
	class InputManager : public Singleton<InputManager>
	{
		set<ActionMap*> actionsMaps;
	private:
		void UpdateActionMaps(const EventInfo& _event);
	public:
		void Update(RenderWindow& _window);
	};

}


