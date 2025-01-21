#pragma once

#include "Macro.h"

template<class T>
class SubclassOf
{
	T objectRef;

public:
	FORCEINLINE T GetSubclassObject() const
	{
		return objectRef;
	}
public:
	SubclassOf()
	{
		objectRef = T();
	}
	SubclassOf(const T& _objectRef)
	{
		objectRef = _objectRef;
	}
};


