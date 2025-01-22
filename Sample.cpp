#include "Sample.h"

Sample::Sample(const string _path)
{
	volume = 1.0f;	
	path = _path;
	//SetVolume(volume);
}

void Sample::Play(const Time& _time)
{
	if (IsSameStatus(1))
	{
		Stop();
	}
	SetVolume(volume);
}
