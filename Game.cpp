#include "Game.h"
#include "ActorManager.h"
#include "CameraManager.h"
#include "TimerManager.h"
#include "InputManager.h"
#include "HUD.h"
#include "Label.h"

using namespace Camera;
using namespace UI;
using namespace Input;

Game::Game()
{
	window = RenderWindow();
}


void Game::Start()
{
    window.create(VideoMode({ 1200, 800 }), "SFML works!");
    M_CAMERA.CreateCamera("DefaultCamera");
    M_HUD.CreateWidget<Label>("Coucou", World);
    //M_CAMERA.CreateCamera(Vector2f(), Vector2f(800.0f, 600.0f));
};

bool Game::Update()
{
    M_INPUT.Update(window);

    TM_Seconds& _timer = M_TIMER;
    _timer.Update();

    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    M_ACTOR.Update(_deltaTime);

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