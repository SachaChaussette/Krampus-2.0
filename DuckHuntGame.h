#pragma once
#include "Game.h"
#include "MeshActor.h"
#include "MusicSample.h"
#include "CameraActor.h"
#include "Duck.h"
#include "Ball.h"

class DuckHuntGame : public Game
{
	MeshActor* background;
	Duck* duck;
	MusicSample* music;
	CameraActor* camera;
	vector<Duck*> duckList;
	Vector2f center;

	//Ball
	Ball* ball;
	MeshActor* floor;
public:
	DuckHuntGame();
	~DuckHuntGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

	Duck* RetrieveFirstDuck();
};