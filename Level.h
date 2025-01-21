#pragma once

#include "Actor.h"

class Level
{
public:
	template <typename T = Actor>
	static T* SpawnActor(const SubclassOf<T>& _ref)
	{
		T* _actor = new T(_ref.GetSubclassObject());
		_actor->Construct();
		return _actor;
	}
};

