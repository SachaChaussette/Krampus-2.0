#pragma once

#include "CoreMinimal.h"

class Game
{
protected:
	RenderWindow window;


public:

	FORCEINLINE virtual bool IsOver()
	{
		return !window.isOpen();
	}

public:
	Game();
	virtual ~Game();

protected:
public:
	virtual void Start();
	virtual bool Update();
	virtual void Stop();

	void UpdateWindow();

};