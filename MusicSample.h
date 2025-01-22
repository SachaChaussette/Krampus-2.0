#pragma once

#include "Sample.h"

class MusicSample : public Sample
{
	using MusicStatus = Music::Status;

	Music* music;

private:
	FORCEINLINE virtual void UpdateVolume(const float _volume) override
	{
		music->setVolume(_volume);
	}
	FORCEINLINE virtual int GetStatus() const override
	{
		return static_cast<int>(music->getStatus());
	}
public:
	FORCEINLINE virtual bool IsAvailable() const override
	{
		return static_cast<MusicStatus>(GetStatus()) != MusicStatus::Playing;
	}
	FORCEINLINE virtual void SetLoop(const bool _isLoop) override
	{
		music->setLooping(_isLoop);
	}
	FORCEINLINE virtual void SetPitch(const float _pitch) override
	{
		music->setPitch(_pitch);
	}


public:
	MusicSample(const string& _path);
	
public:
	virtual void Play(const Time& _time = Time()) override;
	virtual void Pause()override;
	virtual void Stop() override;
};

