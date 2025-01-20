#pragma once

#include "Actor.h"
#include "MeshComponent.h"

class MeshActor : public Actor
{
	MeshComponent* mesh;
	u_int renderMeshToken;
public:

	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		return Super::IsValid(_core);
	}
	FORCEINLINE MeshComponent* GetMesh() const
	{
		return mesh;
	}

	#pragma region Modifier

	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		Super::SetOrigin(_origin);
		mesh->SetOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		Super::SetPosition(_position);
		mesh->SetPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		Super::SetRotation(_rotation);
		mesh->SetRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		Super::SetScale(_scale);
		mesh->SetScale(_scale);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		mesh->Move(_offset);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		Super::Scale(_factor);
		mesh->Scale(_factor);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		Super::Rotate(_angle);
		mesh->Rotate(_angle);
	}

	#pragma endregion	

public:
	MeshActor(const float _radius, const size_t& _pointCount = 30, const string& _path = "", const IntRect& _rect = IntRect());
	MeshActor(const Vector2f _size, const string& _path = "", const IntRect& _rect = IntRect());

private:
	void RenderMesh(RenderWindow& _window);
};
