#pragma once

#include "Game.h"
#include "MeshActor.h"

class MusicSample;
class CircleActor;
class CameraActor;
class Duck;
class Actor;

class DuckHuntGame : public Game
{
	//TODO remove
	MusicSample* music;
	CameraActor* camera;
	Duck* duck;
	Actor* target;
	vector<Duck*> duckList;
	Vector2f center;
	CircleActor* circle;
	float angle;

public:
	//TODO REMOVE
	FORCEINLINE Duck* GetDuck() const
	{
		return duck;
	}
	FORCEINLINE void SetView(const View& _view)
	{
		window.setView(_view);
	}
	FORCEINLINE void RemoveView()
	{
		window.setView(window.getDefaultView());
	}
public:
	DuckHuntGame();
	~DuckHuntGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

	//TODO remove
	Duck* RetrieveFirstDuck();
};