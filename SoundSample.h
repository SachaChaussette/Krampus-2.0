#pragma once

#include "CoreMinimal.h"



class SoundSample
{
	using SoundStatus = SoundSource::Status;

	float volume;
	string path;
	Sound* sound;
	SoundBuffer buffer;

private:
	FORCEINLINE void UpdateVolume(const float _volume)
	{
		sound->setVolume(_volume);
	}
	FORCEINLINE SoundStatus GetStatus() const
	{
		return sound->getStatus();
	}

public:
	FORCEINLINE void SetMuteStatus(const bool _status)
	{
		sound->setVolume(_status ? 0.0f : volume);
	}
	FORCEINLINE void SetVolume(const float _volume)
	{
		sound->setVolume(volume = _volume);
	}
	FORCEINLINE void SetLoop(const bool _isLoop)
	{
		sound->setLooping(_isLoop);
	}
	FORCEINLINE void SetPitch(const float _pitch)
	{
		sound->setPitch(_pitch);
	}
	FORCEINLINE float GetVolume() const
	{
		return sound->getVolume();
	}
	FORCEINLINE string GetPath() const
	{
		return path;
	}
	FORCEINLINE bool IsAvailable() const
	{
		return GetStatus() != SoundStatus::Playing;
	}
public:
	SoundSample(const string& _path);
	~SoundSample();
public:
	void Play(const Time& _time = Time());
	void Pause();
	void Stop();
	void Mute();
};

