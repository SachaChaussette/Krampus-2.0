#pragma once

#include "Game.h"

static Singleton<Game> GAME()
{
	return Game::GetInstance();
}
