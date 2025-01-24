#include "DuckHuntGame.h"
#include "Level.h"
#include "TimerManager.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"
#include "CameraActor.h"

#include "MeshActor.h"
#include "Label.h"
#include "Spawner.h"
#include "Level.h"
#include "Duck.h"
#include "MusicSample.h"
#include "CameraActor.h"
#include "CircleActor.h"
#include "WindEffect.h"

DuckHuntGame::DuckHuntGame() : Game()
{
    // TODO REMOVE
    circle = nullptr;
    angle = 30.0f;
}

DuckHuntGame::~DuckHuntGame()
{

}


void DuckHuntGame::Start()
{
	Super::Start();

    //camera = Level::SpawnActor(CameraActor({ 150.0f }));

    CameraActor* _camera1 = M_CAMERA.CreateCamera("Camera1");
    _camera1->SetViewport(FloatRect({0.5f,1.0f},{}));
    CameraActor* _camera2 = M_CAMERA.CreateCamera("Camera2");
    _camera2->SetViewport(FloatRect({0.5f,0.0f}, {0.5f,1.0f}));
    const Vector2f& _gap = Vector2f(0.0f, 0.0f);
    const Vector2f& _start = Vector2f(150.0f, 150.0f);
    for (u_int _index = 0; _index < 5; _index++)
    {
        CircleActor* _circle = Level::SpawnActor(CircleActor(50.0f, "foekze"));
        _circle->SetOriginAtMiddle();
        _circle->SetPosition(_start +_gap * CAST(float, _index + 1));
    }

    Level::SpawnActor(MeshActor(Vector2f(800, 600), "background", MyTexture::PNG));


    music = M_AUDIO.PlaySample<MusicSample>("spongebob", Audio::MP3);
    ////camera = Level::SpawnActor(CameraActor({}, { 500.0f, 400.0f }));

    //new Timer([&]()
    //    {
    //        Duck* _duck = Level::SpawnActor(/*SubclassOf(*/Duck(Vector2f(50.0f, 50.0f), "duck")/*)*/);
    //        duckList.push_back(_duck);
    //
    //        _duck->SetOriginAtMiddle();
    //
    //        /*for (Actor* _actor : _duck->GetChildren())
    //        {
    //            LOG(Display, _actor->GetName());
    //        }*/

    //        if (!camera->HasTarget())
    //        {
    //            camera->SetTarget(_duck);
    //        }
    //    },
    //    seconds(1.0f),
    //    false,
    //    true
    //);



    //target = Level::SpawnActor(Actor("Actor"));
    //target->SetPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    //duck = Level::SpawnActor(Duck(Vector2f(50.0f, 50.0f), "duck"));
    //duck->SetOriginAtMiddle();
    //const float _gap = 10.0f / 100.0f;
    //duck->SetPosition({ target->GetPosition().x + window.getSize().x * _gap,
    //                    target->GetPosition().y + window.getSize().y * _gap });


    //if (MovementComponent* _movement = duck->GetComponent< MovementComponent>())
    //{
    //    _movement->SetTarget(target);
    //}
    //else if (MovementComponent* _movement = duck->GetMovement())
    //{
    //    _movement->SetTarget(target);
    //}


    /*new Timer([&]()
        {
            WindEffect* _wind = Level::SpawnActor(WindEffect({ 500.0f, 200.0f }, "windEffect"));
            _wind->SetPosition({ -100.0f , 0.0f });
            WindEffect* _wind1 = Level::SpawnActor(WindEffect({ 300.0f, 150.0f }, "windEffect"));
            _wind1->SetPosition({ -100.0f , 100.0f });
            WindEffect* _wind2 = Level::SpawnActor(WindEffect({ 500.0f, 200.0f }, "windEffect"));
            _wind2->SetPosition({ -100.0f , 200.0f });
            WindEffect* _wind3 = Level::SpawnActor(WindEffect({ 300.0f, 150.0f }, "windEffect"));
            _wind3->SetPosition({ -100.0f , 300.0f });
            WindEffect* _wind4 = Level::SpawnActor(WindEffect({ 500.0f, 200.0f }, "windEffect"));
            _wind4->SetPosition({ -100.0f , 400.0f });
        },
        seconds(5.0f),
        true,
        true
    );*/
}

bool DuckHuntGame::Update()
{
	Super::Update();

    //const u_int& _ducksCount = CAST(u_int, duckList.size());
    for (u_int _index = 0; _index < CAST(u_int, duckList.size()); )
    {
        Duck* _duck = duckList[_index];

        if (_duck->IsToDelete())
        {
            duckList.erase(duckList.begin() + _index);
            continue;
        }

        _index++;
    }

    return IsOver();
}

void DuckHuntGame::Stop()
{
	Super::Stop();
	LOG(Display, "DuckHuntGame::Stop");
}
Duck* DuckHuntGame::RetrieveFirstDuck()
{
    if (duckList.empty()) return nullptr;

    const vector<Duck*>::iterator& _it = duckList.begin();
    Duck* _duck = *_it;
    duckList.erase(_it);

    return _duck;
}