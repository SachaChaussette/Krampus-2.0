#pragma once

#include "Macro.h"

u_int GetUniqueId();


int GetRandomNumberInRange(const int _min, const int _max);

template<typename T>
T GetRandomNumberInRange(const T& _min, const T& _max)
{
	random_device _rSeed; // Obtient un graine aléatoire
	mt19937 _gen(_rSeed()); // Initialise le générateur avec la graine
	uniform_real_distribution<T> _distr(_min, _max); // Définit la distribution (les limites)

	return _distr(_gen); // Génération du nombre
}