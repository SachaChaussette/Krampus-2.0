#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"


Game::Game()
{
	window = RenderWindow();

}

Game::~Game()
{

}

void Game::Start()
{
    window.create(VideoMode({800, 600}), "SFML works!");   
};

bool Game::Update()
{
    TM_Seconds& _timer = M_TIMER;
    _timer.Update();

    while (const optional _event = window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            window.close();
            return true;
        }
    }

    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    M_ACTOR.Tick(_deltaTime);        
	
    return IsOver();
}

void Game::UpdateWindow()
{
    window.clear();

    M_CAMERA.RenderAllCameras(window);

    window.display();
}



void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}
