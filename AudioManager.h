#pragma once

#include "Singleton.h"
#include "Sample.h"
#include "Sample.h"

enum AudioExtensionType
{
	MP3,
	WAV,
};

class AudioManager : public Singleton<AudioManager>
{
	bool isMuted;
	string prefixPath;
	multimap<string, Sample*> allSamples;

public:
	FORCEINLINE void RegisterSample(Sample* _sample, const string& _path)
	{
		allSamples.insert(make_pair(_sample->GetPath(), _sample));
	}
	FORCEINLINE string GetExtension(const AudioExtensionType& _type)
	{
		return vector<string>({ ".mp3", ".wav", })[_type];
	}

public:
	AudioManager();
	~AudioManager();

public:
	void PauseSound(const string& _path);
	void StopSound(const string& _path);
	void ToggleMute();

	template <typename T, typename = enable_if<is_base_of_v<Sample, T>>>
	T* PlaySample(const string& _path, const AudioExtensionType& _type)
	{
		//static_assert(is_base_of_v<Sample, T>, "ERREUR CUSTOM !");

		const string _finalPath = prefixPath + _path + GetExtension(_type);

		using Iterator = multimap<string, Sample*>::iterator;
		const pair<Iterator, Iterator>& _activeSamples = allSamples.equal_range(_path);
		Sample* _sample;
		for (Iterator _iterator = _activeSamples.first; _iterator != _activeSamples.second; _iterator++)
		{
			_sample = _iterator->second;
			if (_sample->IsAvailable())
			{
				_sample->Play();
				return Cast<Sample, T>(_sample);
			}
		}			   
		_sample = new T(_finalPath);
		_sample->Play();

		return Cast<Sample, T>(_sample);
	}
};

