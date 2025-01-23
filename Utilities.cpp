#include "Utilities.h"

u_int GetUniqueID()
{
	static u_int _id = 0;
	return ++_id;
}

int GetRandomNumberInRange(const int _min, const int _max)
{
    random_device _rSeed; // Obtient un graine al�atoire
    mt19937 _gen(_rSeed()); // Initialise le g�n�rateur avec la graine
    uniform_int_distribution<> _distr(_min, _max); // D�finit la distribution (les limites)

    return _distr(_gen); // G�n�ration du nombre
}

float DegToRad(const float _degrees)
{
    return _degrees * pi / 180.0f;
}

float RadToDeg(const float _radians)
{
    return  180.0f / _radians * pi;
}
