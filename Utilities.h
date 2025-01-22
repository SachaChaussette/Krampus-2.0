#pragma once

#include "Macro.h"

u_int GetUniqueId();


int GetRandomNumberInRange(const int _min, const int _max);

template<typename T>
T GetRandomNumberInRange(const T& _min, const T& _max)
{
	random_device _rSeed; // Obtient un graine al�atoire
	mt19937 _gen(_rSeed()); // Initialise le g�n�rateur avec la graine
	uniform_real_distribution<T> _distr(_min, _max); // D�finit la distribution (les limites)

	return _distr(_gen); // G�n�ration du nombre
}

template <typename BaseType, typename Type, typename = enable_if_t<is_base_of_v<BaseType, Type>>>
Type* Cast(BaseType* _baseType)
{
	if (!_baseType) return nullptr;
	return dynamic_cast<Type*>(_baseType);
};