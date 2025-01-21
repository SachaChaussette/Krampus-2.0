#include "Duck.h"
#include "Level.h"
#include "TimerManager.h"

Duck::Duck(const Vector2f& _size, const string& _path, const IntRect& _rect) : MeshActor(_size, _path, _rect)
{
    lifeSpan = 5.0f;
    movement = CreateComponent<MovementComponent>();
}

Duck::Duck(const Duck& _other) : MeshActor(_other)
{
    lifeSpan = _other.lifeSpan;
    movement = CreateComponent<MovementComponent>(*_other.movement);
}

void Duck::BeginPlay()
{
    LOG(Display, "coin coin");

    new Timer([&]() { Destroy(); }, seconds(lifeSpan), true);

    Super::BeginPlay();
}
