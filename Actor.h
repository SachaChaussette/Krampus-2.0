#pragma once

#include "Core.h"
#include "RootComponent.h"
#include "ITransformableViewer.h"
#include "ITransformableModifier.h"

class Actor : public Core, public ITransformableViewer, public ITransformableModifier
{
protected:
	set<Component*> components;
	RootComponent* root;


public:
	FORCEINLINE virtual void Move(const Vector2f& _offset) const
	{
		root->Move(_offset);
	}
	template <typename T, typename ...Args>
	FORCEINLINE T* CreateComponent(Args... _args)
	{
		T* _component = new T(this, _args...);
		AddComponent(_component);

		return _component;
	}
	 
	#pragma region Transformable

	#pragma region Viwer

	FORCEINLINE virtual Vector2f GetOrigin() const override 
	{
		return root->GetOrigin();
	}
	FORCEINLINE virtual Vector2f GetPosition() const override
	{
		return root->GetPosition();
	}
	FORCEINLINE virtual Angle GetRotation() const override
	{
		return root->GetRotation();
	}
	FORCEINLINE virtual Vector2f GetScale() const override
	{
		return root->GetScale();
	}
	FORCEINLINE virtual TransformData GetTransform() const override
	{
		return root->GetTransform();
	}

	#pragma endregion

	#pragma region Modifier

	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		root->SetOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		root->SetPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		root->SetRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		root->SetScale(_scale);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		root->Move(_offset);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		root->Scale(_factor);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		root->Rotate(_angle);
	}

	#pragma endregion

	#pragma endregion

	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		// TODO
		return true;
	}
public:
	Actor();
	Actor(const Actor& _actor);
	~Actor();
public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestoy() override;
	virtual void Deconstruct();
	virtual void Construct();

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);

	template<typename Type>
	Type* GetComponent()
	{
		for (Component* _component : components)
		{
			if (Type* _componentCast = dynamic_cast<Type*>(_component)) return _componentCast;
		}
		return nullptr;
	}
};

