#pragma once

#include "Core.h"

class Component : public Core
{
protected:
	class Actor* owner;

public:
	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		// TODO
		return true;
	}
	FORCEINLINE Actor* GetActor() const
	{
		return owner;
	}
public:
	Component(Actor* _owner);
	virtual ~Component();
public:
	virtual void BeginPlay() override {};
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override {};
};

