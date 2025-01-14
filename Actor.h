#pragma once

#include "ShapeObject.h"
#include "Component.h"
#include "Core.h"

class Actor : public Core
{
	ShapeObject* shape;
	set<Component*> components;
public:
	FORCEINLINE ShapeObject* GetShape() const
	{
		return shape;
	}
	FORCEINLINE void SetShape(ShapeObject* _shape)
	{
		shape = _shape;
	}
public:
	Actor() = default;
	Actor(const float _radius, const string& _path, const IntRect& _rect = IntRect(),
		const size_t& _pointCount = 30);
	Actor(const Vector2f _size, const string& _path, const IntRect& _rect = IntRect());
	~Actor();
private:
	void Register();

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestoy() override;
	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
	template<typename Type>
	Type* GetComponent()
	{
		for (Component* _component : components)
		{
			if (is_same_v<decltype(_component), Type>) return dynamic_cast<Type>(_component);
		}
		return nullptr;
		
	}
};

