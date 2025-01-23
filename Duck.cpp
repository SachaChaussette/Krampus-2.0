#include "Duck.h"
#include "TimerManager.h"
#include "Level.h"
#include "AudioManager.h"

Duck::Duck(const Vector2f& _size, const string& _path, const IntRect& _rect) : MeshActor(_size, _path, PNG, _rect, "Duck")
{
	lifeSpan = 10.0f;
	movement = CreateComponent<MovementComponent>();
	animation = CreateComponent<AnimationComponent>();

	//CreateSocket("Socket");
}

Duck::Duck(const Duck& _other) : MeshActor(_other)
{
	lifeSpan = _other.lifeSpan;
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
		{ _timeBetween, Vector2i(0, 0), _spriteSize },
		{ _timeBetween, Vector2i(110, 0), _spriteSize },
		{ _timeBetween, Vector2i(220, 0), _spriteSize },
	};
	//const SpriteData& _spriteData = { 0.2f, Vector2i(), Vector2i(80, 50) };
	AnimationData _animationData = AnimationData(2.0f, _spritesData);
	_animationData.notifies[6] = []() 
	{
		M_AUDIO.PlaySample<SoundSample>("couin", WAV);
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

	new Timer([&]() { Destroy(); }, seconds(lifeSpan), true);
}