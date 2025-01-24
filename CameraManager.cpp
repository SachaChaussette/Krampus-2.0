#include "CameraManager.h"

CameraManager::CameraManager()
{
	allCameras = map<string, CameraActor*>();
	current = nullptr;
}

CameraManager::~CameraManager()
{
	
}

void CameraManager::RenderAllCameras(RenderWindow& _window)
{
	for (const pair<string, CameraActor*> _pair : allCameras)
	{
		_window.setView(*current->GetView());

		for (const pair<u_int, OnRenderWindow>& _renderPair : onRenderWindow)
		{
			_renderPair.second(_window);
		}
	}

	_window.getDefaultView();

	if (allCameras.empty())
	{
		for (const pair<u_int, OnRenderWindow>& _renderPair : onRenderWindow)
		{
			_renderPair.second(_window);
		}
	}
}
