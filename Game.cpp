#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"

// TODO REMOVE
bool TEST(const int _index)
{
    cout << "Index" << _index << endl;
    return _index % 2 == 0;
}

Game::Game()
{
    window = RenderWindow();
    new Actor(20.0f, "images.jpg");
    Actor* _actor = new Actor(50.0f, "images.jpg");
    _actor->GetShape()->Move({ 0.0f, 50.0f });
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
    new Timer([]() 
    { 
        static int _index = 0;
        if (TEST(++_index))
        {
            cout << "coucou" << endl;
        }
    }, Time(seconds(1.0f)), true, true);
}

void Game::Update()
{
    while (window.isOpen())
    {
        TM_Milli& _timer = TM_Milli::GetInstance();
        _timer.Update();
        while (const std::optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                Stop();
            }
        }
        const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        ActorManager::GetInstance().Tick(_deltaTime);

        UpdateWindow();
    }
}

void Game::UpdateWindow()
{
    window.clear();
    for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
    {
        window.draw(*_actor->GetShape()->GetDrawable());
    }
    window.display();
}

void Game::Stop()
{
    window.close();
}

// Apparition sur une carte de manière aléatoire
/*
position aléatoire
forme aléatoire

Taille Différente
Couleur Différente

Retrecissement en continu jusqu'à disparition

*/