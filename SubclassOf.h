#pragma once

#include "Macro.h"

template<class T>
class SubclassOf
{
	T* objectRef;

public:
	FORCEINLINE T GetSubclassObject()
	{
		return *objectRef;
	}
public:
	template<class ...Args>
	SubclassOf(Args... _args)
	{
		objectRef = new T(_args...);
	}
	~SubclassOf()
	{
		delete objectRef;
	}

};


