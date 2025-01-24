#pragma once

#include "Singleton.h"
#include "CameraActor.h"
#include "Level.h"

class CameraManager : public Singleton<CameraManager>
{
	map<string, CameraActor*> allCameras;
	CameraActor* current;
	using OnRenderWindow = function<void(RenderWindow&)>;
	map<u_int, OnRenderWindow> onRenderWindow;

private:
	FORCEINLINE void Register(CameraActor* _camera)
	{
		if (!_camera) return;
		allCameras.insert({ _camera->GetName(), _camera });
		//allCameras.insert({ _camera->GetDisplayName(), _camera });
	}
public:
	FORCEINLINE u_int BindOnRenderWindow(OnRenderWindow _callback)
	{
		u_int _id = GetUniqueID();
		onRenderWindow.insert({ _id, _callback });
		return _id;
	}
	FORCEINLINE void UnbindOnRenderWindow(const u_int& _uniqueId)
	{
		onRenderWindow.erase(_uniqueId);
	}
	FORCEINLINE void SetCurrent(CameraActor* _camera)
	{
		if (!_camera) return;
		current = _camera;
	}
	FORCEINLINE CameraActor* GetCurrent() const
	{
		return current;
	}
	FORCEINLINE CameraActor* GetCameraByName(const string& _name) const
	{
		if (!allCameras.contains(_name)) return nullptr;
		return allCameras.at(_name);
	}

public:
	CameraManager();
	~CameraManager();

	void RenderAllCameras(RenderWindow& _window);

	template<typename Type = CameraActor, typename = enable_if_t<is_base_of_v<CameraActor, Type>>>
	Type* CreateCamera(const string& _name = "Camera")
	{
		Type* _camera = Level::SpawnActor(Type(_name));
		if (!current)
		{
			Register(_camera);
			SetCurrent(_camera);
		}
		return _camera;
	}

};

