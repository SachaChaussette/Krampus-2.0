#pragma once

#include "Component.h"

class AnimationComponent : Component
{
	bool canRun;
	bool isLoop;
	float speed;
	Vector2i spriteSize;
	Vector2i grid;
	Vector2i currentFrame;
	//ShapeObject* shape;

public:
	FORCEINLINE void SetCurrentSize(const int _rowIndex)
	{
		currentFrame.y = _rowIndex;
	}
	FORCEINLINE void SetRunStatus(const bool _status)
	{
		canRun = _status;
	}
	FORCEINLINE void ToggleRunStatus()
	{
		canRun = !canRun;
	}
public:
	AnimationComponent(Actor* _owner, const Vector2i& _spriteSize, const Vector2i& _grid, const float& _speed,
						const bool _isLoop = true);

private:
	void ChangeNextFrame();
	IntRect ComputeFrameRect();
	void Reset();

public:
	virtual void BeginPlay() override {};
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override {};

	void SetCurrentFrame(const Vector2i& _frame);
};

