#pragma once

#include "CoreMinimal.h"

class Core
{
public:
	FORCEINLINE virtual bool IsValid(Core* _core) const = 0;
public:
	virtual void BeginPlay() = 0;
	virtual void Tick(const float _deltaTime) = 0;
	virtual void BeginDestroy() = 0;

	// TODO Check For Using
	template<typename Type>
	Type* Cast(Core* _core)
	{
		if (!IsValid(_core)) return nullptr;
		return dynamic_cast<Type>(_core);
	}
};

