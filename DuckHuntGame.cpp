#include "DuckHuntGame.h"
#include "TimerManager.h"
#include "Level.h"

DuckHuntGame::DuckHuntGame()
{
	background = new MeshActor();
	duck = nullptr;
}

DuckHuntGame::~DuckHuntGame()
{
	delete background;
}

void DuckHuntGame::Start()
{
	Super::Start();

	Level::SpawnActor(MeshActor(Vector2f(606.0f, 404.0f), "background.jpg"));

	new Timer([&]()
	{
		Level::SpawnActor(MeshActor(Vector2f(50.0f, 50.0f), "duckSpriteSheet.png"));
	}, seconds(1.0f), true, true);

	LOG(Display, " DuckHuntGame::Start ");
}

void DuckHuntGame::Update()
{
	Super::Update();
	LOG(Display, " DuckHuntGame::Update ");
}

void DuckHuntGame::Stop()
{
	Super::Stop();
	LOG(Display, " DuckHuntGame::Stop ");
}

void DuckHuntGame::Launch()
{
	Start();
	Update();
	Stop();
}
