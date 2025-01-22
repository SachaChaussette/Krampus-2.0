#pragma once

#include "Sample.h"

class SoundSample : public Sample
{
	using SoundStatus = SoundSource::Status;

	Sound* sound;
	SoundBuffer buffer;

private:
	FORCEINLINE virtual void UpdateVolume(const float _volume) override
	{
		sound->setVolume(_volume);
	}
	FORCEINLINE virtual int GetStatus() const override
	{
		return static_cast<int>(sound->getStatus());
	}
	FORCEINLINE virtual bool IsSameStatus(const u_int& _statusIndex) const override
	{
		if (GetStatus() == _statusIndex) return true;
		return false;
	}

public:

	FORCEINLINE virtual bool IsAvailable() const override
	{
		return static_cast<SoundStatus>(GetStatus()) != SoundStatus::Playing;
	}
	FORCEINLINE virtual void SetLoop(const bool _isLoop) override
	{
		sound->setLooping(_isLoop);
	}
	FORCEINLINE virtual void SetPitch(const float _pitch) override
	{
		sound->setPitch(_pitch);
	}



public:
	SoundSample(const string& _path);
	~SoundSample();
public:
	virtual void Play(const Time& _time = Time()) override;
	virtual void Pause()override;
	virtual void Stop() override;
};

