#pragma once

#include "MeshActor.h"
#include "TimerManager.h"

class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	SubclassOf<MeshActor>* ref;
public:

	Spawner();
	
	~Spawner();
	
private:
	virtual void BeginPlay() override;

	void Spawn_Internal();

public:

	template<typename T>
	void Spawn(SubclassOf<T>& _ref)
	{
		LOG(Display, "aled");

		T* _actor = new T(_ref.GetSubclassObject());
		_actor->Construct();

		const Vector2f& _spawnPosition =
		{
			GetRandomNumberInRange(0.0f, spawnRange),
			GetRandomNumberInRange(0.0f, spawnRange),
		};
		_actor->SetPosition(_spawnPosition);
	}
};

