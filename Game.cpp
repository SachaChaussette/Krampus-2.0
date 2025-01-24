#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"

#include "MeshActor.h"
#include "Label.h"
#include "Spawner.h"
#include "Level.h"
#include "Duck.h"
#include "MusicSample.h"
#include "CameraActor.h"
#include "CircleActor.h"
#include "WindEffect.h"

Game::Game()
{
	window = RenderWindow();

    // TODO REMOVE
    circle = nullptr;
    angle = 30.0f;
}

Game::~Game()
{

}

void Game::Start()
{
    window.create(VideoMode({800, 600}), "SFML works!");
    
    Level::SpawnActor(MeshActor(Vector2f(800, 600), "background", PNG));
    music = M_AUDIO.PlaySample<MusicSample>("spongebob", MP3);
    //camera = Level::SpawnActor(CameraActor({}, { 500.0f, 400.0f }));

    new Timer([&]()
        {
            Duck* _duck = Level::SpawnActor(/*SubclassOf(*/Duck(Vector2f(50.0f, 50.0f), "duck")/*)*/);
            duckList.push_back(_duck);

            _duck->SetOriginAtMiddle();

            /*for (Actor* _actor : _duck->GetChildren())
            {
                LOG(Display, _actor->GetName());
            }*/

            if (!camera->HasTarget())
            {
                camera->SetTarget(_duck);
            }
        },
        seconds(1.0f),
        false,
        true
    );
    


    target = Level::SpawnActor(Actor("Actor"));
    target->SetPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    duck = Level::SpawnActor(Duck(Vector2f(50.0f, 50.0f), "duck"));
    duck->SetOriginAtMiddle();
    const float _gap = 10.0f / 100.0f;
    duck->SetPosition({ target->GetPosition().x + window.getSize().x * _gap,
                        target->GetPosition().y + window.getSize().y * _gap });


    if (MovementComponent* _movement = duck->GetComponent< MovementComponent>())
    {
        _movement->SetTarget(target);
    }
    else if (MovementComponent* _movement = duck->GetMovement())
    {
        _movement->SetTarget(target);
    }


    new Timer([&]()
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

            if (MovementComponent* _movement = duck->GetComponent< MovementComponent>())
            {
                duck->GetComponent<MovementComponent>()->SetRotateSpeed(500.0f);
            }
            else if (MovementComponent* _movement = duck->GetMovement())
            {
                duck->GetComponent<MovementComponent>()->SetRotateSpeed(500.0f);
            }
            
        },
        seconds(10.0f),
        true,
        true
    );

    
};

void Game::Update()
{
	while (window.isOpen()) 
	{
        TM_Seconds& _timer = M_TIMER;
        _timer.Update();

        while (const optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                window.close();
            }
        }

        const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        M_ACTOR.Tick(_deltaTime);

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

        
	}
}

void Game::UpdateWindow()
{
    //TODO check to draw after clear
    //window.setView(*camera->GetView());

    window.clear();

    for (const pair<u_int, OnRenderWindow>& _renderPair : onRenderWindow)
    {
        _renderPair.second(window);
    }

    window.display();
}

Duck* Game::RetrieveFirstDuck()
{
    if (duckList.empty()) return nullptr;

    const vector<Duck*>::iterator& _it = duckList.begin();
    Duck* _duck = *_it;
    duckList.erase(_it);

    return _duck;
}

void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}


void Game::Launch()
{
	Start();
	Update();
	Stop();
}