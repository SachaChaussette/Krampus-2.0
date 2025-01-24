#include "CameraActor.h"
#include "GameManager.h"
#include "Duck.h"
#include "DuckHuntGame.h"

CameraActor::CameraActor(const string& _name) : Actor(_name)
{
	camera = CreateComponent<CameraComponent>();
	target = nullptr;
}

CameraActor::CameraActor(const Vector2f& _center, const Vector2f& _size) : Actor("Camera")
{
	camera = CreateComponent<CameraComponent>(_center, _size);
	target = nullptr;
}

CameraActor::CameraActor(const FloatRect& _rect) : Actor("Camera")
{
	camera = CreateComponent<CameraComponent>(_rect);
	target = nullptr;
}

CameraActor::CameraActor(const CameraActor& _other) : Actor(_other)
{
	camera = CreateComponent<CameraComponent>(_other.camera);
	target = nullptr; //TODO check
}

void CameraActor::Construct()
{
	Super::Construct();
	dynamic_cast<DuckHuntGame*>(M_GAME.GetCurrent())->SetView(*camera->GetView());
}

void CameraActor::Deconstruct()
{
	Super::Deconstruct();
	dynamic_cast<DuckHuntGame*>(M_GAME.GetCurrent())->RemoveView();
}


void CameraActor::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	if (!target) 
	{
		LOG(Warning, "No Target Found !!!");
		return;
	}
	if (target->IsToDelete())
	{
		SetTarget(dynamic_cast<DuckHuntGame*>(M_GAME.GetCurrent())->RetrieveFirstDuck());
		if (!target) return;
	}

	SetPosition(target->GetPosition());
}