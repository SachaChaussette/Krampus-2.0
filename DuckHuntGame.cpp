#include "DuckHuntGame.h"
#include "Level.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"
#include "TextField.h"
#include "Widget.h"
#include "HUD.h"

using namespace UI;

DuckHuntGame::DuckHuntGame() : Game()
{
	background = nullptr;
    music = nullptr;
	floor = nullptr;
	ball = nullptr;
}


void DuckHuntGame::Start()
{
	Super::Start();

    /*Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(463.0f, 260.0f) * 2.0f, "background", JPG)));
    music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));

    const Vector2f& _floorSize = Vector2f(window.getSize().x, window.getSize().y * 0.2f);
    floor = Level::SpawnActor(MeshActor(RectangleShapeData(_floorSize, "Floor", PNG, true)));
    const float _posX = 0.0f;
    const float _posY = window.getSize().y * 0.8f;
    floor->SetPosition(Vector2f(_posX, _posY));
    floor->SetTextureRect(IntRect(Vector2i(), Vector2i(512 * 3, 512)));

    const Vector2f& _wallSize = Vector2f(window.getSize().x * 0.2f, window.getSize().y);
    wall = Level::SpawnActor(MeshActor(RectangleShapeData(_wallSize, "Floor", PNG, true)));
    const float _posX1 = window.getSize().x * 0.8f;
    const float _posY1 = 0.0f;
    wall->SetPosition(Vector2f(_posX1, _posY1));
    wall->SetTextureRect(IntRect(Vector2i(), Vector2i(512 * 3, 512)));

    ball = Level::SpawnActor(Ball(50.0f));
    ball->SetOriginAtMiddle();
    ball->SetPosition(Vector2f(window.getSize().x * 0.5f, window.getSize().y * 0.2f));
    ball->AddForce({200.0f, 0.0f});*/

    ////TODO check
    //if (MovementComponent* _movement = duck->GetComponent<MovementComponent>())
    //{
    //    _movement->SetTarget(_target);
    //}

    M_HUD.CreateWidget<TextField>();
}

bool DuckHuntGame::Update()
{
	Super::Update();

    /*Shape* _ballShape = ball->GetMesh()->GetShape()->GetDrawable();
    const FloatRect& _ballRect = _ballShape->getGlobalBounds();

    Shape* _floorShape = floor->GetMesh()->GetShape()->GetDrawable();
    const FloatRect& _floorRect = _floorShape->getGlobalBounds();

    Shape* _wallShape = wall->GetMesh()->GetShape()->GetDrawable();
    const FloatRect& _wallRect = _wallShape->getGlobalBounds();

    vector<FloatRect> _rects =
    {
        _floorRect,
        _wallRect
    };
    for (FloatRect _rect : _rects)
    {
        if (const optional<FloatRect>& _intersectRect = _ballRect.findIntersection(_rect))
        {
            const Vector2f& _normal = ComputeNormal(*_intersectRect);
            ball->ApplyBounce(_normal);
        }
    }*/
    
    
    return IsOver();
}

void DuckHuntGame::Stop()
{
	Super::Stop();
}

Vector2f DuckHuntGame::ComputeNormal(const FloatRect& _rect)
{
    const Vector2f& _normal = { -_rect.size.y,_rect.size.x };
    const float _norme = Length(_normal);
    return _normal / _norme;
}

float DuckHuntGame::Length(const Vector2f& _vector)
{
    return sqrtf(pow(_vector.x, 2) + pow(_vector.y, 2));
}
