#pragma once

#include "Logger.h"
#include "CustomException.h"
#include "Utilities.h"
#include "SubclassOf.h"

#define M_ACTOR ActorManager::GetInstance()
#define M_TIMER TM_Seconds::GetInstance()
#define M_TEXTURE TextureManager::GetInstance()
#define M_GAME Game::GetInstance()
#define M_FONT FontManager::GetInstance()
#define M_AUDIO AudioManager::GetInstance()
