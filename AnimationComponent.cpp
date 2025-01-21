#include "AnimationComponent.h"
#include "MeshComponent.h"
#include "TextureManager.h"
#include "Actor.h"

AnimationComponent::AnimationComponent(Actor* _owner, const Vector2i& _spriteSize, const Vector2i& _grid, 
										const float& _speed, const bool _isLoop) : Component(_owner)
{
	Reset();

	canRun = false;
	isLoop = _isLoop;
	speed = _speed;
	spriteSize = _spriteSize;
	grid = _grid;
}

void AnimationComponent::ChangeNextFrame()
{
	if (!canRun) return;
	++currentFrame.x;

	if (currentFrame.x >= grid.x)
	{
		if (isLoop)
		{
			currentFrame.x = 0;
		}
		else
		{
			canRun = false;
			return;
		}
	}
	/*M_TEXTURE.Load(shape, shape->GetDrawable().
	owner->GetComponent<MeshComponent>().GetShape()->SetTextureRect(ComputeFrameRect());*/
}

IntRect AnimationComponent::ComputeFrameRect()
{
	const Vector2i& _tileSize = Vector2i(spriteSize.x / grid.x, spriteSize.y / grid.y);
	const Vector2i& _position = Vector2i(currentFrame.x * _tileSize.x, currentFrame.y * _tileSize.y);
	return IntRect(_position, _tileSize);
}

void AnimationComponent::Reset()
{
	currentFrame = Vector2i(0, 0);
}

void AnimationComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	ChangeNextFrame();
}

void AnimationComponent::SetCurrentFrame(const Vector2i& _frame)
{
	currentFrame = _frame;
	/*M_TEXTURE.Load()*/
}
