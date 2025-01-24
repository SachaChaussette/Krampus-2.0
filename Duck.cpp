#include "Duck.h"
#include "TimerManager.h"
#include "Level.h"
#include "AudioManager.h"
#include "Actor.h"

Duck::Duck(const Vector2f& _size, const string& _path, const IntRect& _rect) : MeshActor(_size, _path, MyTexture::PNG, _rect, "Duck")
{
	movement = CreateComponent<MovementComponent>();
	animation = CreateComponent<AnimationComponent>();

	//CreateSocket("Socket");
}

Duck::Duck(const Duck& _other) : MeshActor(_other)
{
	movement = CreateComponent<MovementComponent>(_other.movement);
	animation = CreateComponent<AnimationComponent>();
}


void Duck::Construct()
{
	Super::Construct();

	const float _timeBetween = 0.1f;
	const Vector2i& _spriteSize = Vector2i(110, 110);
	const vector<SpriteData>& _spritesData =
	{
		{ _timeBetween, Vector2i(0, 0), _spriteSize,  },
		{ _timeBetween, Vector2i(110, 0), _spriteSize },
		{ _timeBetween, Vector2i(220, 0), _spriteSize },
	};
	//const SpriteData& _spriteData = { 0.2f, Vector2i(), Vector2i(80, 50) };
	AnimationData _animationData = AnimationData(2.0f, _spritesData, true, true, ROW, true);
	_animationData.notifies[3] = []() 
	{
		//M_AUDIO.PlaySample<SoundSample>("yipeeee", WAV);
	};

	animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
	animation->SetCurrentAnimation("Default");
	animation->StartAnimation();
}

void Duck::Deconstruct()
{
	Super::Deconstruct();
	animation->StopAnimation();
}

void Duck::BeginPlay()
{
	Super::BeginPlay();

}