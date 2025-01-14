#include "Game.h"
#include "ActorManager.h"
#include "TimeManager.h"

void SetupTimer()
{
    // TODO USAGE ?
    TimeManager& _manager = TimeManager::GetInstance();
    _manager.AddActor(new Timer([&]() {cout << "timer1" << endl; }, Time(milliseconds(5000)), true, false));
    _manager.AddActor(new Timer([&]() {cout << "timer2" << endl; }, Time(milliseconds(500)), true, false));
}
Game::Game()
{
    window = RenderWindow();
    new Actor(20.0f, "Cow");
    Actor* _actor = new Actor(50.0f, "Cow");
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
    // TODO REMOVE
    SetupTimer();
    window.create(VideoMode({ 800, 600 }), "SFML works!");
}

void Game::Update()
{
    while (window.isOpen())
    {
        while (const std::optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                Stop();
            }
        }
        // TODO REMOVE
        TimeManager::GetInstance().Update();
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