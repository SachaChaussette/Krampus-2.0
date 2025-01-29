#include "CameraManager.h"

Camera::CameraManager::CameraManager()
{
	allRendersData = map<u_int, RenderData>();
	allCameras = map<string, CameraActor*>();
	current = nullptr;
}


void Camera::CameraManager::RenderAllCameras(RenderWindow& _window)
{
	vector<RenderData> _renderWidgets;
	bool _isFirst = true;

	/*for (u_int _index = 0; _index < allElements.size(); _index++)
	{
		
		for (const pair<multimap<int, u_int>>& _pair : allElements.equal_range(_index))
	}*/
	

	// pour chaque caméra
	for (const pair<string, CameraActor*> _pair : allCameras)
	{
		_window.setView(*_pair.second->GetView());

		// je draw tous les éléments que je veux
		for (const pair<u_int, RenderData>& _renderPair : allRendersData)
		{
			if (_isFirst && _renderPair.second.type == Screen)
			{
				_renderWidgets.push_back(_renderPair.second);
				continue;
			}
			// je draw l'élément
			_renderPair.second.callback(_window);
		}		
		_isFirst = false;
	}
	_window.setView(_window.getDefaultView());

	for (const RenderData& _data : _renderWidgets)
	{
		_data.callback(_window);
	}
}