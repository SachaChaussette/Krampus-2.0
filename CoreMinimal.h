#pragma once

#pragma warning (disable : 4275)

// STL
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <typeindex>
#include <typeinfo>
#include <cassert>

// OLD
#include <math.h>
#include <conio.h>

// Collections
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Fichier Ext
#include "Logger.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define INLINE __inline
#define FORCEINLINE __forceinline
#define Super __super
#define SLEEP(_duration) sf::sleep(_duration)

#define DISPLAY(_text, _endl) if(_endl) cout << endl; \
										cout << _text;

using namespace std;
using namespace sf;

typedef unsigned short u_short;
typedef unsigned int u_int;
typedef long long l_long;
