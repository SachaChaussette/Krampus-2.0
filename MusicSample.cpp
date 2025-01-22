#include "MusicSample.h"
#include "AudioManager.h"

MusicSample::MusicSample(const string& _path) : Sample(_path)
{
	music = new Music();

	if (!music->openFromFile(_path))
	{
		LOG(Error, "Invalid path : " + _path);
		music = nullptr;
		return;
	}

	M_AUDIO.RegisterSample(this, GetPath());
}

void MusicSample::Play(const Time& _time)
{
	music->play();
}

void MusicSample::Pause()
{
	music->pause();
}

void MusicSample::Stop()
{
	music->stop();
}
