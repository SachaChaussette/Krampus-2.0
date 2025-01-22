#include "AudioManager.h"

AudioManager::AudioManager()
{
	isMuted = false;
	allSamples = multimap<string, Sample*>();
	prefixPath = "Assets/Sounds/";
}

AudioManager::~AudioManager()
{
	for (pair<string, Sample*> _samplePair : allSamples)
	{
		delete _samplePair.second;
	}
}



void AudioManager::PauseSound(const string& _path)
{
	allSamples.extract(_path).mapped()->Stop();
}

void AudioManager::StopSound(const string& _path)
{
	allSamples.extract(_path).mapped()->Pause();
}


void AudioManager::ToggleMute()
{
	isMuted = !isMuted;

	for (pair<string, Sample*> _samplePair : allSamples)
	{
		_samplePair.second->SetMuteStatus(isMuted);
	}
}


