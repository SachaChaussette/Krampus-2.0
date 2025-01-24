#include "DuckHuntGame.h"
#include "Level.h"
#include "TimerManager.h"
#include "AudioManager.h"

#include "Spawner.h"
#include "Level.h"
#include "MusicSample.h"
#include "CameraActor.h"
#include "CameraManager.h"
#include "CircleActor.h"
#include "Ball.h"

DuckHuntGame::DuckHuntGame() : Game()
{
	background = nullptr;
	duck = nullptr;
    camera = nullptr;
    duckList = vector<Duck*>();
}

DuckHuntGame::~DuckHuntGame()
{
	delete background;
}


void DuckHuntGame::Start()
{
	Super::Start();

    Level::SpawnActor(MeshActor(Vector2f(463.0f, 260.0f) * 2.0f, "background", PNG));
    //music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));

    /*
    CameraActor* _camera1 = M_CAMERA.CreateCamera("Camera1");
    _camera1->SetViewport(FloatRect({ 0.0f, 0.0f }, { 0.5f, 1.0f }));
    _camera1->SetPosition({ 350.f, 300.f });
    //_camera1->SetScale({ 300.f, 200.f });
    _camera1->Zoom(1.5f);

    CameraActor* _camera2 = M_CAMERA.CreateCamera("Camera2");
    _camera2->SetViewport(FloatRect({ 0.5f, 0.0f }, { 0.5f, 1.0f }));

    const Vector2f& _start = Vector2f(100.0f, 100.0f);
    const Vector2f& _gap = Vector2f(150.0f, 150.0f);

    for (u_int _index = 0; _index < 5; _index++)
    {
        CircleActor* _circle = Level::SpawnActor(CircleActor(75.0f));
        _circle->SetOriginAtMiddle();
        _circle->SetPosition(_start + _gap * CAST(float, _index));
    }
    */

    // lerp du mouvement
    floor = Level::SpawnActor(MeshActor(Vector2f(window.getSize().x, window.getSize().y * 0.2f)));
    const float _posX = 0.0f;
    const float _posY = window.getSize().y * 0.8f;
    floor->SetPosition(Vector2f(_posX, _posY));

    ball = Level::SpawnActor(Ball(50.0f));
    ball->SetOriginAtMiddle();
    ball->SetPosition(Vector2f(window.getSize()) / 2.0f);


    ////TODO check
    //if (MovementComponent* _movement = duck->GetComponent<MovementComponent>())
    //{
    //    _movement->SetTarget(_target);
    //}
}

bool DuckHuntGame::Update()
{
    Super::Update();

    //const u_int& _ducksCount = CAST(u_int, duckList.size());
    /*for (u_int _index = 0; _index < CAST(u_int, duckList.size()); )
    {
        Duck* _duck = duckList[_index];

        if (_duck->IsToDelete())
        {
            duckList.erase(duckList.begin() + _index);
            continue;
        }

        _index++;
    }*/


    Shape* _floorShape = floor->GetMesh()->GetShape()->GetDrawable();
    const FloatRect& _floorRect = _floorShape->getGlobalBounds();

    Shape* _ballShape = ball->GetMesh()->GetShape()->GetDrawable();
    const FloatRect& _ballRect = _ballShape->getGlobalBounds();

    if (_ballRect.findIntersection(_floorRect))
    {
        ball->ApplyBounce();
    }

    return IsOver();
}


void DuckHuntGame::Stop()
{
	Super::Stop();
}


Duck* DuckHuntGame::RetrieveFirstDuck()
{
    if (duckList.empty()) return nullptr;

    const vector<Duck*>::iterator& _it = duckList.begin();
    Duck* _duck = *_it;
    duckList.erase(_it);

    return _duck;
}