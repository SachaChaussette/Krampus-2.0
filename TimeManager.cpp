#include "TimeManager.h"

Timer::Timer(const function<void()>& _callback, const Time& _time, const bool _startRunning, 
			const bool _isLoop)
{
	isRunning = _startRunning;
	isLoop = _isLoop;
	currentTime = 0.0;
	duration = _time.asMilliseconds();
	callback = _callback;
}

void Timer::Start()
{
	Reset();
	Resume();
}

void Timer::Update(const float _deltaTime)
{
	if (!isRunning) return;

	currentTime += _deltaTime;
	// TODO REMOVE
	cout << currentTime << endl;
	if (currentTime >= duration)
	{
		if (callback)
		{
			callback();
		}

		if (!isLoop)
		{
			Stop();
		}

		Reset();
	}
}

void Timer::Stop()
{
	//delete this;

	// TODO REMOVE DANS LE SET
}

void Timer::Resume()
{
	isRunning = true;
}

void Timer::Reset()
{
	currentTime = 0.0;
}

void Timer::Pause()
{
	isRunning = false;
}

TimeManager::TimeManager()
{
	allTimers = set<Timer*>();
}

TimeManager::~TimeManager()
{
	for (Timer* _timer : allTimers)
	{
		delete _timer;
	}
}

void TimeManager::Update()
{
	// TODO REMOVE
	float _deltaTime = 100.0f;
	for (Timer* _timer : allTimers)
	{
		_timer->Update(_deltaTime);
	}
}

void TimeManager::Pause()
{
	for (Timer* _timer : allTimers)
	{
		_timer->Pause();
	}
}
