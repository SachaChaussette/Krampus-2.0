#pragma once
#include "CoreMinimal.h"
#include "Actor.h"

// SpawnActor		-> Constructeur + Construct()
// Instance de ref  -> Constructeur

class Level
{
public:
	template <typename T = Actor>
	static T* SpawnActor()
	{
		const SubclassOf<T>& _ref = SubclassOf(T());
		return SpawnActor(_ref);
	}

	template <typename T = Actor>
	static T* SpawnActor(const SubclassOf<T>& _ref)
	{
		T* _actor = new T(_ref.GetObject());
		_actor->Construct();
		return _actor;
	}

	template <typename T = Actor>
	static T* SpawnActor(const T& _ref)
	{
		T* _actor = new T(_ref);
		_actor->Construct();
		return _actor;
	}
};