#include "Duck.h"
#include "Level.h"
#include "TimerManager.h"

Duck::Duck(const Vector2f& _size, const string& _path, const IntRect& _rect) : MeshActor(_size, _path, _rect)
{
    lifeSpan = 5.0f;
    movement = CreateComponent<MovementComponent>();
    animation = CreateComponent<AnimationComponent>();
}

Duck::Duck(const Duck& _other) : MeshActor(_other)
{
    lifeSpan = _other.lifeSpan;
    movement = CreateComponent<MovementComponent>(_other.movement);
    animation = CreateComponent<AnimationComponent>(_other.animation);
}

void Duck::BeginPlay()
{
    LOG(Display, "coin coin");

    new Timer([&]() { Destroy(); }, seconds(lifeSpan), true);

    Super::BeginPlay();
}

void Duck::Construct()
{
    Super::Construct();

    const SpriteData& _spriteData = { 0.2f, Vector2i(), Vector2i(110, 110) };
    const AnimationData& _animationData = AnimationData(3, 2.0f, _spriteData);
    animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animationData));
    animation->SetCurrentAnimation("Default");
    animation->StartAnimation();

    BeginPlay();
}


void Duck::Deconstruct()
{
    Super::Deconstruct();

    //animation->StopAnimation();
}
