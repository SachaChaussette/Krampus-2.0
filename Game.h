#pragma once

#include "Singleton.h"


class Game : public Singleton<Game>
{
	RenderWindow window;

	using OnRenderWindow = function<void(RenderWindow&)>;

	map<u_int, OnRenderWindow> onRenderWindow;

public:
	FORCEINLINE u_int BindOnRenderWindow(OnRenderWindow _callback)
	{
		u_int _id = GetUniqueId();
		onRenderWindow.insert({ _id, _callback });
		return _id;
	}
	FORCEINLINE void UnbindOnRenderWindow(const u_int& _uniqueID)
	{
		onRenderWindow.erase(_uniqueID);
	}
public:
	Game();
	~Game();

protected:
	virtual void Start();
	virtual void Update();
	virtual void Stop();

public:
	void UpdateWindow();
	virtual void Launch();
};

