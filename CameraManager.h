#pragma once
#include "Singleton.h"
#include "CameraActor.h"
#include "Level.h"
#include "RenderType.h"

namespace Camera
{
	

	struct RenderData
	{
		RenderType type;
		using RenderCallback = function<void(RenderWindow&)>;
		RenderCallback callback;

	public:
		RenderData(const RenderCallback& _callback, const RenderType& _type = World)
		{
			callback = _callback;
			type = _type;
		}
	};

	class CameraManager : public Singleton<CameraManager>
	{
		multimap<int, u_int> allElements;

		map<u_int, RenderData> allRendersData;
		map<string, CameraActor*> allCameras;
		CameraActor* current;

	public:
		FORCEINLINE u_int BindOnRenderWindow(const RenderData& _data)
		{
			u_int _id = GetUniqueID();
			allRendersData.insert({ _id, _data });
			return _id;
		}
		FORCEINLINE void UnbindOnRenderWindow(const u_int& _uniqueId)
		{
			if (!allRendersData.contains(_uniqueId)) return;
			allRendersData.erase(_uniqueId);
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
	private:
		FORCEINLINE void Register(CameraActor* _camera)
		{
			if (!_camera) return;
			allCameras.insert({ _camera->GetName(), _camera });
			//allCameras.insert({ _camera->GetDisplayName(), _camera });
		}

	public:
		CameraManager();

		void RenderAllCameras(RenderWindow& _window);

		template <typename Type = CameraActor, typename ...Args, IS_BASE_OF(CameraActor, Type)>
		Type* CreateCamera(Args... _args)
		{
			Type* _camera = Level::SpawnActor(Type(_args...));
			Register(_camera);

			if (!current)
			{
				SetCurrent(_camera);
			}

			return _camera;
		}
	};
}
