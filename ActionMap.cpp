#include "ActionMap.h"

Input::ActionMap::ActionMap()
{
	isActive = false;
	name = "DefaultActionMap";
	actions = map<string, Action*>();
}

void Input::ActionMap::Update(const EventInfo& _event)
{
	if (!isActive) return;

	for (pair<string, Action*> _action : actions)
	{
		_action.second->TryToExecute(_event);
	}
}
