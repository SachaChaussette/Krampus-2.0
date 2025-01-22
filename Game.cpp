#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "MeshActor.h"
#include "Label.h"
#include "Level.h"
#include "Spawner.h"
#include "SubclassOf.h"
#include "Duck.h"
#include "SoundSample.h"



Game::Game()
{
    window = RenderWindow();
}

Game::~Game()
{

}

void Game::Launch()
{
    Start();
    Update();
}
void Game::Start()
{
    window.create(VideoMode({ 800, 600 }), "SFML works!");

    Level::SpawnActor(MeshActor(Vector2f(800.0f, 600.0f), "background.jpg"));
   
    new Timer([&]()
    {
        //Level::SpawnActor(*(new Duck(Vector2f(50.0f, 50.0f), "duck.png", IntRect(Vector2i(), Vector2i(110, 110)))));
        Level::SpawnActor(SubclassOf<Duck>(Duck(Vector2f(50.0f, 50.0f), "duck.png", IntRect(Vector2i(), Vector2i(110, 110)))));
        M_AUDIO.PlaySample<SoundSample>("yipeeee", WAV);
    }, seconds(2.0f), true, true);
    
        


  /*  new Timer([]() 
    { 
        static int _index = 0;
        if (TEST(++_index))
        {
            LOG(Display, "coucou");
        }
    }, Time(seconds(1.0f)), true, false);*/
    //new Label("Aled", "Starjedi", TTF);
    //MeshActor _mesh = MeshActor(20.0f, 30, "images.jpg");

    //Spawner* _spawner = new Spawner();
    //Spawner* _spawner = Level::SpawnActor<Spawner>();

    /*
    MeshActor _meshActorObject = MeshActor(20.0f, 30, "Charm");
    SubclassOf<MeshActor> _meshActorRef = SubclassOf<MeshActor>(&_meshActorObject);
    MeshActor* _meshActor = Level::SpawnActor<MeshActor>(_meshActorRef);
    */

    /*_mesh2->GetMesh()->GetShape()->Move({ 50.0f, 0.0f });

    FloatRect _boundingBox1 = _mesh1->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();
    FloatRect _boundingBox2 = _mesh2->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();

    if (const optional<FloatRect>& _intersection = _boundingBox1.findIntersection(_boundingBox2))
    {
        LOG(Display, to_string(_intersection.value().getCenter().x) + " / " + to_string(_intersection.value().getCenter().y));
    }*/



    M_ACTOR.BeginPlay();
}

void Game::Update()
{
    while (window.isOpen())
    {
        TM_Seconds& _timer = M_TIMER;
        _timer.Update();
        while (const std::optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                window.close();
            }
        }   
        const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        
        M_ACTOR.Tick(_deltaTime);
    }
}

void Game::UpdateWindow()
{
    window.clear();
    for (const pair<u_int, OnRenderWindow>& _renderPair : onRenderWindow)
    {
        _renderPair.second(window);
    }
    window.display();
}

void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}

